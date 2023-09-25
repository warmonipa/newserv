#pragma once

#include <memory>
#include <phosg/JSON.hh>
#include <string>
#include <unordered_map>
#include <vector>

#include "Text.hh"

class LicenseIndex;

struct License {
  enum Flag : uint32_t {
    // clang-format off
      KICK_USER         = 0x00000001,
      BAN_USER          = 0x00000002,
      SILENCE_USER      = 0x00000004,
      CHANGE_LOBBY_INFO = 0x00000008,
      CHANGE_EVENT      = 0x00000010,
      ANNOUNCE          = 0x00000020,
      FREE_JOIN_GAMES   = 0x00000040,
      UNLOCK_GAMES      = 0x00000080,
      DEBUG             = 0x01000000,
      MODERATOR         = 0x00000007,
      ADMINISTRATOR     = 0x000000FF,
      ROOT              = 0x010000FF,

      UNUSED_BITS       = 0xFEFFFF00,
    // clang-format on
  };

  uint32_t serial_number = 0;
  std::string access_key;
  std::string gc_password;
  std::string bb_username;
  std::string bb_password;

  uint32_t flags = 0;
  uint64_t ban_end_time = 0; // 0 = not banned

  uint32_t ep3_current_meseta = 0;
  uint32_t ep3_total_meseta_earned = 0;

  License() = default;
  explicit License(const JSON& json);

  JSON json() const;
  void save() const;
  void delete_file() const;

  std::string str() const;
};

class LicenseIndex {
public:
  class incorrect_password : public std::invalid_argument {
  public:
    incorrect_password() : invalid_argument("incorrect password") {}
  };

  class incorrect_access_key : public std::invalid_argument {
  public:
    incorrect_access_key() : invalid_argument("incorrect access key") {}
  };

  class missing_license : public std::invalid_argument {
  public:
    missing_license() : invalid_argument("missing license") {}
  };

  LicenseIndex();
  ~LicenseIndex() = default;

  size_t count() const;
  std::shared_ptr<License> get(uint32_t serial_number) const;
  std::vector<std::shared_ptr<License>> all() const;

  void add(std::shared_ptr<License> l);
  void remove(uint32_t serial_number);

  std::shared_ptr<License> verify_v1_v2(uint32_t serial_number, const std::string& access_key) const;
  std::shared_ptr<License> verify_gc(uint32_t serial_number, const std::string& access_key) const;
  std::shared_ptr<License> verify_gc(uint32_t serial_number, const std::string& access_key, const std::string& password) const;
  std::shared_ptr<License> verify_bb(const std::string& username, const std::string& password) const;

protected:
  std::unordered_map<std::string, std::shared_ptr<License>> bb_username_to_license;
  std::unordered_map<uint32_t, std::shared_ptr<License>> serial_number_to_license;
};
