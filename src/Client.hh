#pragma once

#include <netinet/in.h>

#include <memory>

#include "Channel.hh"
#include "CommandFormats.hh"
#include "Episode3/BattleRecord.hh"
#include "Episode3/Tournament.hh"
#include "FileContentsCache.hh"
#include "FunctionCompiler.hh"
#include "License.hh"
#include "PSOEncryption.hh"
#include "PSOProtocol.hh"
#include "PatchFileIndex.hh"
#include "Player.hh"
#include "QuestScript.hh"
#include "Text.hh"

extern const uint64_t CLIENT_CONFIG_MAGIC;

class Server;
struct Lobby;

struct ClientOptions {
  // Options used on both game and proxy server
  bool switch_assist;
  bool infinite_hp;
  bool infinite_tp;
  bool debug;
  int16_t override_section_id; // -1 = no override
  int16_t override_lobby_event; // -1 = no override
  int16_t override_lobby_number; // -1 = no override
  int64_t override_random_seed;

  // Options used only on proxy server
  bool save_files;
  bool enable_chat_commands;
  bool enable_chat_filter;
  bool enable_player_notifications;
  bool suppress_client_pings;
  bool suppress_remote_login;
  bool zero_remote_guild_card;
  bool ep3_infinite_meseta;
  bool ep3_infinite_time;
  bool red_name;
  bool blank_name;
  int64_t function_call_return_value; // -1 = don't block function calls

  ClientOptions();
};

struct Client : public std::enable_shared_from_this<Client> {
  enum Flag {
    // Client is DC Network Trial Edition, which is missing a lot of features
    // and uses some different command numbers than any other version
    IS_DC_TRIAL_EDITION = 0x00002000,
    // A 90 01 command has been sent (which proto will send a 93 in response to,
    // and actual DCv1 will send a 92)
    CHECKED_FOR_DC_V1_PROTOTYPE = 0x00080000,
    // Client is DC v1 prototype
    IS_DC_V1_PROTOTYPE = 0x00040000,
    // Client is DC v1
    IS_DC_V1 = 0x00000010,
    // Client is GC Episodes 1&2 Trial Edition, which is much more like PC than
    // actual GC Episodes 1&2 - it uses PC encryption and is missing most of the
    // features added in Episodes 1&2
    IS_GC_TRIAL_EDITION = 0x00200000,
    // Client is GC Episode 3 Trial Edition, which is fairly close to the final
    // Episode 3 build, but is missing a few commands that we'll have to avoid
    // sending
    IS_EP3_TRIAL_EDITION = 0x00400000,
    // For patch server clients, client is Blue Burst rather than PC
    IS_BB_PATCH = 0x00000001,
    // After joining a lobby, client will no longer send D6 commands when they
    // close message boxes
    NO_D6_AFTER_LOBBY = 0x00000002,
    // Client has the above flag and has already joined a lobby, or is not GC
    NO_D6 = 0x00000004,
    // Client is Episode 3, should be able to see CARD lobbies, and should only
    // be able to see/join games with the EPISODE_3_ONLY flag
    IS_EPISODE_3 = 0x00000008,
    // Client disconnects if it receives B2 (send_function_call)
    NO_SEND_FUNCTION_CALL = 0x00000200,
    // Client requires doubly-encrypted code section in send_function_call
    ENCRYPTED_SEND_FUNCTION_CALL = 0x00000800,
    // Client supports send_function_call but does not actually run the code
    SEND_FUNCTION_CALL_CHECKSUM_ONLY = 0x00001000,
    // Client supports send_function_call and clears its caches properly before
    // calling the function (so we don't need to patch it)
    SEND_FUNCTION_CALL_NO_CACHE_PATCH = 0x00020000,
    // Client is vulnerable to a buffer overflow that we can use to enable
    // send_function_call
    USE_OVERFLOW_FOR_SEND_FUNCTION_CALL = 0x00008000,

    // Client is loading into a game
    LOADING = 0x00000020,
    // Client is loading a quest
    LOADING_QUEST = 0x00000040,
    // Client is loading a joinable quest that has already started
    LOADING_RUNNING_QUEST = 0x00100000,
    // Client is waiting for other players to join a tournament game
    LOADING_TOURNAMENT = 0x00010000,
    // Client is in the information menu (login server only)
    IN_INFORMATION_MENU = 0x00000080,
    // Client is at the welcome message (login server only)
    AT_WELCOME_MESSAGE = 0x00000100,
    // Client has already received a 97 (enable saves) command, so don't show
    // the programs menu anymore
    SAVE_ENABLED = 0x00000400,
    // Client has received newserv's Episode 3 card definitions, so don't send
    // them again
    HAS_EP3_CARD_DEFS = 0x00004000,
    // Client has received newserv's Episode 3 media updates, so don't send them
    // again
    HAS_EP3_MEDIA_UPDATES = 0x00800000,

    UNUSED_FLAG_BITS = 0xFF010000,
  };

  std::weak_ptr<Server> server;
  std::weak_ptr<ServerState> server_state;
  uint64_t id;
  PrefixedLogger log;

  // License & account
  std::shared_ptr<License> license;

  // Note: these fields are included in the client config. On GC, the client
  // config can be up to 0x20 bytes; on BB it can be 0x28 bytes. We don't use
  // all of that space.
  uint8_t bb_game_state;
  uint32_t flags;
  uint32_t specific_version;

  // Network
  Channel channel;
  struct sockaddr_storage next_connection_addr;
  ServerBehavior server_behavior;
  bool should_disconnect;
  bool should_send_to_lobby_server;
  bool should_send_to_proxy_server;
  uint32_t proxy_destination_address;
  uint16_t proxy_destination_port;
  std::unordered_map<std::string, std::function<void()>> disconnect_hooks;

  // Patch server
  std::vector<PatchFileChecksumRequest> patch_file_checksum_requests;

  // Lobby/positioning
  ClientOptions options;
  float x;
  float z;
  uint32_t area;
  std::weak_ptr<Lobby> lobby;
  uint8_t lobby_client_id;
  uint8_t lobby_arrow_color;
  int64_t preferred_lobby_id; // <0 = no preference
  ClientGameData game_data;
  std::unique_ptr<struct event, void (*)(struct event*)> save_game_data_event;
  std::unique_ptr<struct event, void (*)(struct event*)> send_ping_event;
  std::unique_ptr<struct event, void (*)(struct event*)> idle_timeout_event;
  int16_t card_battle_table_number;
  uint16_t card_battle_table_seat_number;
  uint16_t card_battle_table_seat_state;
  std::weak_ptr<Episode3::Tournament::Team> ep3_tournament_team;
  std::shared_ptr<Episode3::BattleRecord> ep3_prev_battle_record;
  std::shared_ptr<const Menu> last_menu_sent;

  // Miscellaneous (used by chat commands)
  uint32_t next_exp_value; // next EXP value to give
  G_SwitchStateChanged_6x05 last_switch_enabled_command;
  bool can_chat;
  std::string pending_bb_save_username;
  uint8_t pending_bb_save_player_index;
  std::deque<std::function<void(uint32_t, uint32_t)>> function_call_response_queue;

  // File loading state
  uint32_t dol_base_addr;
  std::shared_ptr<DOLFileIndex::DOLFile> loading_dol_file;
  std::unordered_map<std::string, std::shared_ptr<const std::string>> sending_files;

  Client(
      shared_ptr<Server> server,
      struct bufferevent* bev,
      GameVersion version,
      ServerBehavior server_behavior);
  ~Client();

  void reschedule_ping_and_timeout_events();

  inline GameVersion version() const {
    return this->channel.version;
  }
  QuestScriptVersion quest_version() const;

  void set_license(std::shared_ptr<License> l);

  std::shared_ptr<ServerState> require_server_state() const;
  std::shared_ptr<Lobby> require_lobby() const;

  ClientConfig export_config() const;
  ClientConfigBB export_config_bb() const;
  void import_config(const ClientConfig& cc);
  void import_config(const ClientConfigBB& cc);

  static void dispatch_save_game_data(evutil_socket_t, short, void* ctx);
  void save_game_data();
  static void dispatch_send_ping(evutil_socket_t, short, void* ctx);
  void send_ping();
  static void dispatch_idle_timeout(evutil_socket_t, short, void* ctx);
  void idle_timeout();
};
