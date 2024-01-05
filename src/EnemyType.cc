#include "BattleParamsIndex.hh"

#include <phosg/Filesystem.hh>
#include <phosg/Strings.hh>

#include "Loggers.hh"
#include "PSOEncryption.hh"
#include "StaticGameData.hh"

using namespace std;

template <>
const char* name_for_enum<EnemyType>(EnemyType type) {
  switch (type) {
    case EnemyType::UNKNOWN:
      return "UNKNOWN";
    case EnemyType::NONE:
      return "NONE";
    case EnemyType::NON_ENEMY_NPC:
      return "NON_ENEMY_NPC";
    case EnemyType::AL_RAPPY:
      return "AL_RAPPY";
    case EnemyType::ASTARK:
      return "ASTARK";
    case EnemyType::BA_BOOTA:
      return "BA_BOOTA";
    case EnemyType::BARBA_RAY:
      return "BARBA_RAY";
    case EnemyType::BARBAROUS_WOLF:
      return "BARBAROUS_WOLF";
    case EnemyType::BEE_L:
      return "BEE_L";
    case EnemyType::BEE_R:
      return "BEE_R";
    case EnemyType::BOOMA:
      return "BOOMA";
    case EnemyType::BOOTA:
      return "BOOTA";
    case EnemyType::BULCLAW:
      return "BULCLAW";
    case EnemyType::CANADINE:
      return "CANADINE";
    case EnemyType::CANADINE_GROUP:
      return "CANADINE_GROUP";
    case EnemyType::CANANE:
      return "CANANE";
    case EnemyType::CHAOS_BRINGER:
      return "CHAOS_BRINGER";
    case EnemyType::CHAOS_SORCERER:
      return "CHAOS_SORCERER";
    case EnemyType::CLAW:
      return "CLAW";
    case EnemyType::DARK_BELRA:
      return "DARK_BELRA";
    case EnemyType::DARK_FALZ_1:
      return "DARK_FALZ_1";
    case EnemyType::DARK_FALZ_2:
      return "DARK_FALZ_2";
    case EnemyType::DARK_FALZ_3:
      return "DARK_FALZ_3";
    case EnemyType::DARK_GUNNER:
      return "DARK_GUNNER";
    case EnemyType::DARVANT:
      return "DARVANT";
    case EnemyType::DARVANT_ULTIMATE:
      return "DARVANT_ULTIMATE";
    case EnemyType::DE_ROL_LE:
      return "DE_ROL_LE";
    case EnemyType::DE_ROL_LE_BODY:
      return "DE_ROL_LE_BODY";
    case EnemyType::DE_ROL_LE_MINE:
      return "DE_ROL_LE_MINE";
    case EnemyType::DEATH_GUNNER:
      return "DEATH_GUNNER";
    case EnemyType::DEL_LILY:
      return "DEL_LILY";
    case EnemyType::DEL_RAPPY:
      return "DEL_RAPPY";
    case EnemyType::DEL_RAPPY_ALT:
      return "DEL_RAPPY_ALT";
    case EnemyType::DELBITER:
      return "DELBITER";
    case EnemyType::DELDEPTH:
      return "DELDEPTH";
    case EnemyType::DELSABER:
      return "DELSABER";
    case EnemyType::DIMENIAN:
      return "DIMENIAN";
    case EnemyType::DOLMDARL:
      return "DOLMDARL";
    case EnemyType::DOLMOLM:
      return "DOLMOLM";
    case EnemyType::DORPHON:
      return "DORPHON";
    case EnemyType::DORPHON_ECLAIR:
      return "DORPHON_ECLAIR";
    case EnemyType::DRAGON:
      return "DRAGON";
    case EnemyType::DUBCHIC:
      return "DUBCHIC";
    case EnemyType::DUBWITCH:
      return "DUBWITCH";
    case EnemyType::EGG_RAPPY:
      return "EGG_RAPPY";
    case EnemyType::EPSIGUARD:
      return "EPSIGUARD";
    case EnemyType::EPSILON:
      return "EPSILON";
    case EnemyType::EVIL_SHARK:
      return "EVIL_SHARK";
    case EnemyType::GAEL:
      return "GAEL";
    case EnemyType::GAL_GRYPHON:
      return "GAL_GRYPHON";
    case EnemyType::GARANZ:
      return "GARANZ";
    case EnemyType::GEE:
      return "GEE";
    case EnemyType::GI_GUE:
      return "GI_GUE";
    case EnemyType::GIBBLES:
      return "GIBBLES";
    case EnemyType::GIGOBOOMA:
      return "GIGOBOOMA";
    case EnemyType::GILLCHIC:
      return "GILLCHIC";
    case EnemyType::GIRTABLULU:
      return "GIRTABLULU";
    case EnemyType::GOBOOMA:
      return "GOBOOMA";
    case EnemyType::GOL_DRAGON:
      return "GOL_DRAGON";
    case EnemyType::GORAN:
      return "GORAN";
    case EnemyType::GORAN_DETONATOR:
      return "GORAN_DETONATOR";
    case EnemyType::GRASS_ASSASSIN:
      return "GRASS_ASSASSIN";
    case EnemyType::GUIL_SHARK:
      return "GUIL_SHARK";
    case EnemyType::HALLO_RAPPY:
      return "HALLO_RAPPY";
    case EnemyType::HIDOOM:
      return "HIDOOM";
    case EnemyType::HILDEBEAR:
      return "HILDEBEAR";
    case EnemyType::HILDEBLUE:
      return "HILDEBLUE";
    case EnemyType::ILL_GILL:
      return "ILL_GILL";
    case EnemyType::KONDRIEU:
      return "KONDRIEU";
    case EnemyType::LA_DIMENIAN:
      return "LA_DIMENIAN";
    case EnemyType::LOVE_RAPPY:
      return "LOVE_RAPPY";
    case EnemyType::MERICAROL:
      return "MERICAROL";
    case EnemyType::MERICUS:
      return "MERICUS";
    case EnemyType::MERIKLE:
      return "MERIKLE";
    case EnemyType::MERILLIA:
      return "MERILLIA";
    case EnemyType::MERILTAS:
      return "MERILTAS";
    case EnemyType::MERISSA_A:
      return "MERISSA_A";
    case EnemyType::MERISSA_AA:
      return "MERISSA_AA";
    case EnemyType::MIGIUM:
      return "MIGIUM";
    case EnemyType::MONEST:
      return "MONEST";
    case EnemyType::MORFOS:
      return "MORFOS";
    case EnemyType::MOTHMANT:
      return "MOTHMANT";
    case EnemyType::NANO_DRAGON:
      return "NANO_DRAGON";
    case EnemyType::NAR_LILY:
      return "NAR_LILY";
    case EnemyType::OLGA_FLOW_1:
      return "OLGA_FLOW_1";
    case EnemyType::OLGA_FLOW_2:
      return "OLGA_FLOW_2";
    case EnemyType::PAL_SHARK:
      return "PAL_SHARK";
    case EnemyType::PAN_ARMS:
      return "PAN_ARMS";
    case EnemyType::PAZUZU:
      return "PAZUZU";
    case EnemyType::PAZUZU_ALT:
      return "PAZUZU_ALT";
    case EnemyType::PIG_RAY:
      return "PIG_RAY";
    case EnemyType::POFUILLY_SLIME:
      return "POFUILLY_SLIME";
    case EnemyType::POUILLY_SLIME:
      return "POUILLY_SLIME";
    case EnemyType::POISON_LILY:
      return "POISON_LILY";
    case EnemyType::PYRO_GORAN:
      return "PYRO_GORAN";
    case EnemyType::RAG_RAPPY:
      return "RAG_RAPPY";
    case EnemyType::RECOBOX:
      return "RECOBOX";
    case EnemyType::RECON:
      return "RECON";
    case EnemyType::SAINT_MILLION:
      return "SAINT_MILLION";
    case EnemyType::SAINT_RAPPY:
      return "SAINT_RAPPY";
    case EnemyType::SAND_RAPPY:
      return "SAND_RAPPY";
    case EnemyType::SAND_RAPPY_ALT:
      return "SAND_RAPPY_ALT";
    case EnemyType::SATELLITE_LIZARD:
      return "SATELLITE_LIZARD";
    case EnemyType::SATELLITE_LIZARD_ALT:
      return "SATELLITE_LIZARD_ALT";
    case EnemyType::SAVAGE_WOLF:
      return "SAVAGE_WOLF";
    case EnemyType::SHAMBERTIN:
      return "SHAMBERTIN";
    case EnemyType::SINOW_BEAT:
      return "SINOW_BEAT";
    case EnemyType::SINOW_BERILL:
      return "SINOW_BERILL";
    case EnemyType::SINOW_GOLD:
      return "SINOW_GOLD";
    case EnemyType::SINOW_SPIGELL:
      return "SINOW_SPIGELL";
    case EnemyType::SINOW_ZELE:
      return "SINOW_ZELE";
    case EnemyType::SINOW_ZOA:
      return "SINOW_ZOA";
    case EnemyType::SO_DIMENIAN:
      return "SO_DIMENIAN";
    case EnemyType::UL_GIBBON:
      return "UL_GIBBON";
    case EnemyType::VOL_OPT_1:
      return "VOL_OPT_1";
    case EnemyType::VOL_OPT_2:
      return "VOL_OPT_2";
    case EnemyType::VOL_OPT_AMP:
      return "VOL_OPT_AMP";
    case EnemyType::VOL_OPT_CORE:
      return "VOL_OPT_CORE";
    case EnemyType::VOL_OPT_MONITOR:
      return "VOL_OPT_MONITOR";
    case EnemyType::VOL_OPT_PILLAR:
      return "VOL_OPT_PILLAR";
    case EnemyType::YOWIE:
      return "YOWIE";
    case EnemyType::YOWIE_ALT:
      return "YOWIE_ALT";
    case EnemyType::ZE_BOOTA:
      return "ZE_BOOTA";
    case EnemyType::ZOL_GIBBON:
      return "ZOL_GIBBON";
    case EnemyType::ZU:
      return "ZU";
    case EnemyType::ZU_ALT:
      return "ZU_ALT";
    case EnemyType::MAX_ENEMY_TYPE:
      return "MAX_ENEMY_TYPE";
    default:
      throw logic_error("invalid enemy type");
  }
}

template <>
EnemyType enum_for_name<EnemyType>(const char* name) {
  static const unordered_map<string, EnemyType> names({
      {"UNKNOWN", EnemyType::UNKNOWN},
      {"NONE", EnemyType::NONE},
      {"NON_ENEMY_NPC", EnemyType::NON_ENEMY_NPC},
      {"AL_RAPPY", EnemyType::AL_RAPPY},
      {"ASTARK", EnemyType::ASTARK},
      {"BA_BOOTA", EnemyType::BA_BOOTA},
      {"BARBA_RAY", EnemyType::BARBA_RAY},
      {"BARBAROUS_WOLF", EnemyType::BARBAROUS_WOLF},
      {"BEE_L", EnemyType::BEE_L},
      {"BEE_R", EnemyType::BEE_R},
      {"BOOMA", EnemyType::BOOMA},
      {"BOOTA", EnemyType::BOOTA},
      {"BULCLAW", EnemyType::BULCLAW},
      {"CANADINE", EnemyType::CANADINE},
      {"CANADINE_GROUP", EnemyType::CANADINE_GROUP},
      {"CANANE", EnemyType::CANANE},
      {"CHAOS_BRINGER", EnemyType::CHAOS_BRINGER},
      {"CHAOS_SORCERER", EnemyType::CHAOS_SORCERER},
      {"CLAW", EnemyType::CLAW},
      {"DARK_BELRA", EnemyType::DARK_BELRA},
      {"DARK_FALZ_1", EnemyType::DARK_FALZ_1},
      {"DARK_FALZ_2", EnemyType::DARK_FALZ_2},
      {"DARK_FALZ_3", EnemyType::DARK_FALZ_3},
      {"DARK_GUNNER", EnemyType::DARK_GUNNER},
      {"DARVANT", EnemyType::DARVANT},
      {"DARVANT_ULTIMATE", EnemyType::DARVANT_ULTIMATE},
      {"DE_ROL_LE", EnemyType::DE_ROL_LE},
      {"DE_ROL_LE_BODY", EnemyType::DE_ROL_LE_BODY},
      {"DE_ROL_LE_MINE", EnemyType::DE_ROL_LE_MINE},
      {"DEATH_GUNNER", EnemyType::DEATH_GUNNER},
      {"DEL_LILY", EnemyType::DEL_LILY},
      {"DEL_RAPPY", EnemyType::DEL_RAPPY},
      {"DEL_RAPPY_ALT", EnemyType::DEL_RAPPY_ALT},
      {"DELBITER", EnemyType::DELBITER},
      {"DELDEPTH", EnemyType::DELDEPTH},
      {"DELSABER", EnemyType::DELSABER},
      {"DIMENIAN", EnemyType::DIMENIAN},
      {"DOLMDARL", EnemyType::DOLMDARL},
      {"DOLMOLM", EnemyType::DOLMOLM},
      {"DORPHON", EnemyType::DORPHON},
      {"DORPHON_ECLAIR", EnemyType::DORPHON_ECLAIR},
      {"DRAGON", EnemyType::DRAGON},
      {"DUBCHIC", EnemyType::DUBCHIC},
      {"DUBWITCH", EnemyType::DUBWITCH},
      {"EGG_RAPPY", EnemyType::EGG_RAPPY},
      {"EPSIGUARD", EnemyType::EPSIGUARD},
      {"EPSILON", EnemyType::EPSILON},
      {"EVIL_SHARK", EnemyType::EVIL_SHARK},
      {"GAEL", EnemyType::GAEL},
      {"GAL_GRYPHON", EnemyType::GAL_GRYPHON},
      {"GARANZ", EnemyType::GARANZ},
      {"GEE", EnemyType::GEE},
      {"GI_GUE", EnemyType::GI_GUE},
      {"GIBBLES", EnemyType::GIBBLES},
      {"GIGOBOOMA", EnemyType::GIGOBOOMA},
      {"GILLCHIC", EnemyType::GILLCHIC},
      {"GIRTABLULU", EnemyType::GIRTABLULU},
      {"GOBOOMA", EnemyType::GOBOOMA},
      {"GOL_DRAGON", EnemyType::GOL_DRAGON},
      {"GORAN", EnemyType::GORAN},
      {"GORAN_DETONATOR", EnemyType::GORAN_DETONATOR},
      {"GRASS_ASSASSIN", EnemyType::GRASS_ASSASSIN},
      {"GUIL_SHARK", EnemyType::GUIL_SHARK},
      {"HALLO_RAPPY", EnemyType::HALLO_RAPPY},
      {"HIDOOM", EnemyType::HIDOOM},
      {"HILDEBEAR", EnemyType::HILDEBEAR},
      {"HILDEBLUE", EnemyType::HILDEBLUE},
      {"ILL_GILL", EnemyType::ILL_GILL},
      {"KONDRIEU", EnemyType::KONDRIEU},
      {"LA_DIMENIAN", EnemyType::LA_DIMENIAN},
      {"LOVE_RAPPY", EnemyType::LOVE_RAPPY},
      {"MERICAROL", EnemyType::MERICAROL},
      {"MERICUS", EnemyType::MERICUS},
      {"MERIKLE", EnemyType::MERIKLE},
      {"MERILLIA", EnemyType::MERILLIA},
      {"MERILTAS", EnemyType::MERILTAS},
      {"MERISSA_A", EnemyType::MERISSA_A},
      {"MERISSA_AA", EnemyType::MERISSA_AA},
      {"MIGIUM", EnemyType::MIGIUM},
      {"MONEST", EnemyType::MONEST},
      {"MORFOS", EnemyType::MORFOS},
      {"MOTHMANT", EnemyType::MOTHMANT},
      {"NANO_DRAGON", EnemyType::NANO_DRAGON},
      {"NAR_LILY", EnemyType::NAR_LILY},
      {"OLGA_FLOW_1", EnemyType::OLGA_FLOW_1},
      {"OLGA_FLOW_2", EnemyType::OLGA_FLOW_2},
      {"PAL_SHARK", EnemyType::PAL_SHARK},
      {"PAN_ARMS", EnemyType::PAN_ARMS},
      {"PAZUZU", EnemyType::PAZUZU},
      {"PAZUZU_ALT", EnemyType::PAZUZU_ALT},
      {"PIG_RAY", EnemyType::PIG_RAY},
      {"POFUILLY_SLIME", EnemyType::POFUILLY_SLIME},
      {"POUILLY_SLIME", EnemyType::POUILLY_SLIME},
      {"POISON_LILY", EnemyType::POISON_LILY},
      {"PYRO_GORAN", EnemyType::PYRO_GORAN},
      {"RAG_RAPPY", EnemyType::RAG_RAPPY},
      {"RECOBOX", EnemyType::RECOBOX},
      {"RECON", EnemyType::RECON},
      {"SAINT_MILLION", EnemyType::SAINT_MILLION},
      {"SAINT_RAPPY", EnemyType::SAINT_RAPPY},
      {"SAND_RAPPY", EnemyType::SAND_RAPPY},
      {"SAND_RAPPY_ALT", EnemyType::SAND_RAPPY_ALT},
      {"SATELLITE_LIZARD", EnemyType::SATELLITE_LIZARD},
      {"SATELLITE_LIZARD_ALT", EnemyType::SATELLITE_LIZARD_ALT},
      {"SAVAGE_WOLF", EnemyType::SAVAGE_WOLF},
      {"SHAMBERTIN", EnemyType::SHAMBERTIN},
      {"SINOW_BEAT", EnemyType::SINOW_BEAT},
      {"SINOW_BERILL", EnemyType::SINOW_BERILL},
      {"SINOW_GOLD", EnemyType::SINOW_GOLD},
      {"SINOW_SPIGELL", EnemyType::SINOW_SPIGELL},
      {"SINOW_ZELE", EnemyType::SINOW_ZELE},
      {"SINOW_ZOA", EnemyType::SINOW_ZOA},
      {"SO_DIMENIAN", EnemyType::SO_DIMENIAN},
      {"UL_GIBBON", EnemyType::UL_GIBBON},
      {"VOL_OPT_1", EnemyType::VOL_OPT_1},
      {"VOL_OPT_2", EnemyType::VOL_OPT_2},
      {"VOL_OPT_AMP", EnemyType::VOL_OPT_AMP},
      {"VOL_OPT_CORE", EnemyType::VOL_OPT_CORE},
      {"VOL_OPT_MONITOR", EnemyType::VOL_OPT_MONITOR},
      {"VOL_OPT_PILLAR", EnemyType::VOL_OPT_PILLAR},
      {"YOWIE", EnemyType::YOWIE},
      {"YOWIE_ALT", EnemyType::YOWIE_ALT},
      {"ZE_BOOTA", EnemyType::ZE_BOOTA},
      {"ZOL_GIBBON", EnemyType::ZOL_GIBBON},
      {"ZU", EnemyType::ZU},
      {"ZU_ALT", EnemyType::ZU_ALT},
      {"MAX_ENEMY_TYPE", EnemyType::MAX_ENEMY_TYPE},
  });
  return names.at(name);
}

bool enemy_type_valid_for_episode(Episode episode, EnemyType enemy_type) {
  switch (episode) {
    case Episode::EP1:
      switch (enemy_type) {
        case EnemyType::MOTHMANT:
        case EnemyType::MONEST:
        case EnemyType::SAVAGE_WOLF:
        case EnemyType::BARBAROUS_WOLF:
        case EnemyType::POISON_LILY:
        case EnemyType::NAR_LILY:
        case EnemyType::SINOW_BEAT:
        case EnemyType::CANADINE:
        case EnemyType::CANADINE_GROUP:
        case EnemyType::CANANE:
        case EnemyType::CHAOS_SORCERER:
        case EnemyType::CHAOS_BRINGER:
        case EnemyType::DARK_BELRA:
        case EnemyType::DE_ROL_LE:
        case EnemyType::DRAGON:
        case EnemyType::SINOW_GOLD:
        case EnemyType::RAG_RAPPY:
        case EnemyType::AL_RAPPY:
        case EnemyType::NANO_DRAGON:
        case EnemyType::DUBCHIC:
        case EnemyType::GILLCHIC:
        case EnemyType::GARANZ:
        case EnemyType::DARK_GUNNER:
        case EnemyType::BULCLAW:
        case EnemyType::CLAW:
        case EnemyType::VOL_OPT_2:
        case EnemyType::POUILLY_SLIME:
        case EnemyType::POFUILLY_SLIME:
        case EnemyType::PAN_ARMS:
        case EnemyType::HIDOOM:
        case EnemyType::MIGIUM:
        case EnemyType::DARVANT:
        case EnemyType::DARVANT_ULTIMATE:
        case EnemyType::DARK_FALZ_1:
        case EnemyType::DARK_FALZ_2:
        case EnemyType::DARK_FALZ_3:
        case EnemyType::HILDEBEAR:
        case EnemyType::HILDEBLUE:
        case EnemyType::BOOMA:
        case EnemyType::GOBOOMA:
        case EnemyType::GIGOBOOMA:
        case EnemyType::GRASS_ASSASSIN:
        case EnemyType::EVIL_SHARK:
        case EnemyType::PAL_SHARK:
        case EnemyType::GUIL_SHARK:
        case EnemyType::DELSABER:
        case EnemyType::DIMENIAN:
        case EnemyType::LA_DIMENIAN:
        case EnemyType::SO_DIMENIAN:
          return true;
        default:
          return false;
      }
    case Episode::EP2:
      switch (enemy_type) {
        case EnemyType::MOTHMANT:
        case EnemyType::MONEST:
        case EnemyType::SAVAGE_WOLF:
        case EnemyType::BARBAROUS_WOLF:
        case EnemyType::POISON_LILY:
        case EnemyType::NAR_LILY:
        case EnemyType::SINOW_BERILL:
        case EnemyType::GEE:
        case EnemyType::CHAOS_SORCERER:
        case EnemyType::DELBITER:
        case EnemyType::DARK_BELRA:
        case EnemyType::BARBA_RAY:
        case EnemyType::GOL_DRAGON:
        case EnemyType::SINOW_SPIGELL:
        case EnemyType::RAG_RAPPY:
        case EnemyType::LOVE_RAPPY:
        case EnemyType::SAINT_RAPPY:
        case EnemyType::EGG_RAPPY:
        case EnemyType::HALLO_RAPPY:
        case EnemyType::GI_GUE:
        case EnemyType::DUBCHIC:
        case EnemyType::GILLCHIC:
        case EnemyType::GARANZ:
        case EnemyType::GAL_GRYPHON:
        case EnemyType::EPSILON:
        case EnemyType::DEL_LILY:
        case EnemyType::ILL_GILL:
        case EnemyType::OLGA_FLOW_1:
        case EnemyType::OLGA_FLOW_2:
        case EnemyType::GAEL:
        case EnemyType::DELDEPTH:
        case EnemyType::PAN_ARMS:
        case EnemyType::HIDOOM:
        case EnemyType::MIGIUM:
        case EnemyType::MERICAROL:
        case EnemyType::UL_GIBBON:
        case EnemyType::ZOL_GIBBON:
        case EnemyType::GIBBLES:
        case EnemyType::MORFOS:
        case EnemyType::RECOBOX:
        case EnemyType::RECON:
        case EnemyType::SINOW_ZOA:
        case EnemyType::SINOW_ZELE:
        case EnemyType::MERIKLE:
        case EnemyType::MERICUS:
        case EnemyType::HILDEBEAR:
        case EnemyType::HILDEBLUE:
        case EnemyType::MERILLIA:
        case EnemyType::MERILTAS:
        case EnemyType::GRASS_ASSASSIN:
        case EnemyType::DOLMOLM:
        case EnemyType::DOLMDARL:
        case EnemyType::DELSABER:
        case EnemyType::DIMENIAN:
        case EnemyType::LA_DIMENIAN:
        case EnemyType::SO_DIMENIAN:
          return true;
        default:
          return false;
      }
    case Episode::EP4:
      switch (enemy_type) {
        case EnemyType::BOOTA:
        case EnemyType::ZE_BOOTA:
        case EnemyType::BA_BOOTA:
        case EnemyType::SAND_RAPPY:
        case EnemyType::DEL_RAPPY:
        case EnemyType::ZU:
        case EnemyType::PAZUZU:
        case EnemyType::ASTARK:
        case EnemyType::SATELLITE_LIZARD:
        case EnemyType::YOWIE:
        case EnemyType::DORPHON:
        case EnemyType::DORPHON_ECLAIR:
        case EnemyType::GORAN:
        case EnemyType::PYRO_GORAN:
        case EnemyType::GORAN_DETONATOR:
        case EnemyType::SAND_RAPPY_ALT:
        case EnemyType::DEL_RAPPY_ALT:
        case EnemyType::MERISSA_A:
        case EnemyType::MERISSA_AA:
        case EnemyType::ZU_ALT:
        case EnemyType::PAZUZU_ALT:
        case EnemyType::SATELLITE_LIZARD_ALT:
        case EnemyType::YOWIE_ALT:
        case EnemyType::GIRTABLULU:
        case EnemyType::SAINT_MILLION:
        case EnemyType::SHAMBERTIN:
        case EnemyType::KONDRIEU:
          return true;
        default:
          return false;
      }
    default:
      return false;
  }
}

uint8_t battle_param_index_for_enemy_type(Episode episode, EnemyType enemy_type) {
  switch (episode) {
    case Episode::EP1:
      switch (enemy_type) {
        case EnemyType::MOTHMANT:
          return 0x00;
        case EnemyType::MONEST:
          return 0x01;
        case EnemyType::SAVAGE_WOLF:
          return 0x02;
        case EnemyType::BARBAROUS_WOLF:
          return 0x03;
        case EnemyType::POISON_LILY:
          return 0x04;
        case EnemyType::NAR_LILY:
          return 0x05;
        case EnemyType::SINOW_BEAT:
          return 0x06;
        case EnemyType::CANADINE:
          return 0x07;
        case EnemyType::CANADINE_GROUP:
          return 0x08;
        case EnemyType::CANANE:
          return 0x09;
        case EnemyType::CHAOS_SORCERER:
          return 0x0A;
        case EnemyType::CHAOS_BRINGER:
          return 0x0D;
        case EnemyType::DARK_BELRA:
          return 0x0E;
        case EnemyType::DE_ROL_LE:
          return 0x0F;
        case EnemyType::DRAGON:
          return 0x12;
        case EnemyType::SINOW_GOLD:
          return 0x13;
        case EnemyType::RAG_RAPPY:
          return 0x18;
        case EnemyType::AL_RAPPY:
          return 0x19;
        case EnemyType::NANO_DRAGON:
          return 0x1A;
        case EnemyType::DUBCHIC:
          return 0x1B;
        case EnemyType::GILLCHIC:
          return 0x1C;
        case EnemyType::GARANZ:
          return 0x1D;
        case EnemyType::DARK_GUNNER:
          return 0x1E;
        case EnemyType::BULCLAW:
          return 0x1F;
        case EnemyType::CLAW:
          return 0x20;
        case EnemyType::VOL_OPT_2:
          return 0x25;
        case EnemyType::POFUILLY_SLIME:
          return 0x30;
        case EnemyType::POUILLY_SLIME:
          return 0x2F;
        case EnemyType::PAN_ARMS:
          return 0x31;
        case EnemyType::HIDOOM:
          return 0x32;
        case EnemyType::MIGIUM:
          return 0x33;
        case EnemyType::DARVANT:
          return 0x35;
        case EnemyType::DARVANT_ULTIMATE:
          return 0x39;
        case EnemyType::DARK_FALZ_1:
          return 0x36;
        case EnemyType::DARK_FALZ_2:
          return 0x37;
        case EnemyType::DARK_FALZ_3:
          return 0x38;
        case EnemyType::HILDEBEAR:
          return 0x49;
        case EnemyType::HILDEBLUE:
          return 0x4A;
        case EnemyType::BOOMA:
          return 0x4B;
        case EnemyType::GOBOOMA:
          return 0x4C;
        case EnemyType::GIGOBOOMA:
          return 0x4D;
        case EnemyType::GRASS_ASSASSIN:
          return 0x4E;
        case EnemyType::EVIL_SHARK:
          return 0x4F;
        case EnemyType::PAL_SHARK:
          return 0x50;
        case EnemyType::GUIL_SHARK:
          return 0x51;
        case EnemyType::DELSABER:
          return 0x52;
        case EnemyType::DIMENIAN:
          return 0x53;
        case EnemyType::LA_DIMENIAN:
          return 0x54;
        case EnemyType::SO_DIMENIAN:
          return 0x55;
        default:
          throw runtime_error(string_printf("%s does not have battle parameters in Episode 1", name_for_enum(enemy_type)));
      }
      break;
    case Episode::EP2:
      switch (enemy_type) {
        case EnemyType::MOTHMANT:
          return 0x00;
        case EnemyType::MONEST:
          return 0x01;
        case EnemyType::SAVAGE_WOLF:
          return 0x02;
        case EnemyType::BARBAROUS_WOLF:
          return 0x03;
        case EnemyType::POISON_LILY:
          return 0x04;
        case EnemyType::NAR_LILY:
          return 0x05;
        case EnemyType::SINOW_BERILL:
          return 0x06;
        case EnemyType::GEE:
          return 0x07;
        case EnemyType::CHAOS_SORCERER:
          return 0x0A;
        case EnemyType::DELBITER:
          return 0x0D;
        case EnemyType::DARK_BELRA:
          return 0x0E;
        case EnemyType::BARBA_RAY:
          return 0x0F;
        case EnemyType::GOL_DRAGON:
          return 0x12;
        case EnemyType::SINOW_SPIGELL:
          return 0x13;
        case EnemyType::RAG_RAPPY:
          return 0x18;
        case EnemyType::LOVE_RAPPY:
        case EnemyType::SAINT_RAPPY:
        case EnemyType::EGG_RAPPY:
        case EnemyType::HALLO_RAPPY:
          return 0x19;
        case EnemyType::GI_GUE:
          return 0x1A;
        case EnemyType::DUBCHIC:
          return 0x1B;
        case EnemyType::GILLCHIC:
          return 0x1C;
        case EnemyType::GARANZ:
          return 0x1D;
        case EnemyType::GAL_GRYPHON:
          return 0x1E;
        case EnemyType::EPSILON:
          return 0x23;
        case EnemyType::DEL_LILY:
          return 0x25;
        case EnemyType::ILL_GILL:
          return 0x26;
        case EnemyType::OLGA_FLOW_1:
          return 0x2B;
        case EnemyType::OLGA_FLOW_2:
          return 0x2C;
        case EnemyType::GAEL:
          return 0x2E;
        case EnemyType::DELDEPTH:
          return 0x30;
        case EnemyType::PAN_ARMS:
          return 0x31;
        case EnemyType::HIDOOM:
          return 0x32;
        case EnemyType::MIGIUM:
          return 0x33;
        case EnemyType::MERICAROL:
          return 0x3A;
        case EnemyType::UL_GIBBON:
          return 0x3B;
        case EnemyType::ZOL_GIBBON:
          return 0x3C;
        case EnemyType::GIBBLES:
          return 0x3D;
        case EnemyType::MORFOS:
          return 0x40;
        case EnemyType::RECOBOX:
          return 0x41;
        case EnemyType::RECON:
          return 0x42;
        case EnemyType::SINOW_ZOA:
          return 0x43;
        case EnemyType::SINOW_ZELE:
          return 0x44;
        case EnemyType::MERIKLE:
          return 0x45;
        case EnemyType::MERICUS:
          return 0x46;
        case EnemyType::HILDEBEAR:
          return 0x49;
        case EnemyType::HILDEBLUE:
          return 0x4A;
        case EnemyType::MERILLIA:
          return 0x4B;
        case EnemyType::MERILTAS:
          return 0x4C;
        case EnemyType::GRASS_ASSASSIN:
          return 0x4E;
        case EnemyType::DOLMOLM:
          return 0x4F;
        case EnemyType::DOLMDARL:
          return 0x50;
        case EnemyType::DELSABER:
          return 0x52;
        case EnemyType::DIMENIAN:
          return 0x53;
        case EnemyType::LA_DIMENIAN:
          return 0x54;
        case EnemyType::SO_DIMENIAN:
          return 0x55;
        default:
          throw runtime_error(string_printf("%s does not have battle parameters in Episode 2", name_for_enum(enemy_type)));
      }
      break;
    case Episode::EP4:
      switch (enemy_type) {
        case EnemyType::BOOTA:
          return 0x00;
        case EnemyType::ZE_BOOTA:
          return 0x01;
        case EnemyType::BA_BOOTA:
          return 0x03;
        case EnemyType::SAND_RAPPY:
          return 0x05;
        case EnemyType::DEL_RAPPY:
          return 0x06;
        case EnemyType::ZU:
          return 0x07;
        case EnemyType::PAZUZU:
          return 0x08;
        case EnemyType::ASTARK:
          return 0x09;
        case EnemyType::SATELLITE_LIZARD:
          return 0x0D;
        case EnemyType::YOWIE:
          return 0x0E;
        case EnemyType::DORPHON:
          return 0x0F;
        case EnemyType::DORPHON_ECLAIR:
          return 0x10;
        case EnemyType::GORAN:
          return 0x11;
        case EnemyType::PYRO_GORAN:
          return 0x12;
        case EnemyType::GORAN_DETONATOR:
          return 0x13;
        case EnemyType::SAND_RAPPY_ALT:
          return 0x17;
        case EnemyType::DEL_RAPPY_ALT:
          return 0x18;
        case EnemyType::MERISSA_A:
          return 0x19;
        case EnemyType::MERISSA_AA:
          return 0x1A;
        case EnemyType::ZU_ALT:
          return 0x1B;
        case EnemyType::PAZUZU_ALT:
          return 0x1C;
        case EnemyType::SATELLITE_LIZARD_ALT:
          return 0x1D;
        case EnemyType::YOWIE_ALT:
          return 0x1E;
        case EnemyType::GIRTABLULU:
          return 0x1F;
        case EnemyType::SAINT_MILLION:
        case EnemyType::SHAMBERTIN:
        case EnemyType::KONDRIEU:
          return 0x22;
        default:
          throw runtime_error(string_printf("%s does not have battle parameters in Episode 4", name_for_enum(enemy_type)));
      }
      break;
    default:
      throw logic_error("incorrect episode in battle param lookup");
  }
  throw logic_error("fallthrough case in battle param lookup");
}

uint8_t rare_table_index_for_enemy_type(EnemyType enemy_type) {
  switch (enemy_type) {
    case EnemyType::AL_RAPPY:
      return 0x06;
    case EnemyType::ASTARK:
      return 0x41;
    case EnemyType::BA_BOOTA:
      return 0x4F;
    case EnemyType::BARBA_RAY:
      return 0x49;
    case EnemyType::BARBAROUS_WOLF:
      return 0x08;
    case EnemyType::BOOMA:
      return 0x09;
    case EnemyType::BOOTA:
      return 0x4D;
    case EnemyType::BULCLAW:
      return 0x28;
    case EnemyType::CANADINE:
    case EnemyType::CANADINE_GROUP:
      return 0x1C;
    case EnemyType::CANANE:
      return 0x1D;
    case EnemyType::CHAOS_BRINGER:
      return 0x24;
    case EnemyType::CHAOS_SORCERER:
      return 0x1F;
    case EnemyType::CLAW:
      return 0x26;
    case EnemyType::DARK_BELRA:
      return 0x25;
    case EnemyType::DARK_FALZ_2:
      return 0x2F;
    case EnemyType::DARK_FALZ_3:
      return 0x2F;
    case EnemyType::DARK_GUNNER:
      return 0x22;
    case EnemyType::DE_ROL_LE:
      return 0x2D;
    case EnemyType::DEL_LILY:
      return 0x53;
    case EnemyType::DEL_RAPPY:
      return 0x57;
    case EnemyType::DEL_RAPPY_ALT:
      return 0x58;
    case EnemyType::DELBITER:
      return 0x48;
    case EnemyType::DELDEPTH:
      return 0x47;
    case EnemyType::DELSABER:
      return 0x1E;
    case EnemyType::DIMENIAN:
      return 0x29;
    case EnemyType::DOLMDARL:
      return 0x41;
    case EnemyType::DOLMOLM:
      return 0x40;
    case EnemyType::DORPHON:
      return 0x50;
    case EnemyType::DORPHON_ECLAIR:
      return 0x51;
    case EnemyType::DRAGON:
      return 0x2C;
    case EnemyType::DUBCHIC:
      return 0x18;
    case EnemyType::EGG_RAPPY:
      return 0x51;
    case EnemyType::EPSILON:
      return 0x54;
    case EnemyType::EVIL_SHARK:
      return 0x10;
    case EnemyType::GAL_GRYPHON:
      return 0x4D;
    case EnemyType::GARANZ:
      return 0x19;
    case EnemyType::GEE:
      return 0x36;
    case EnemyType::GI_GUE:
      return 0x37;
    case EnemyType::GIBBLES:
      return 0x3D;
    case EnemyType::GIGOBOOMA:
      return 0x0B;
    case EnemyType::GILLCHIC:
      return 0x32;
    case EnemyType::GIRTABLULU:
      return 0x48;
    case EnemyType::GOBOOMA:
      return 0x0A;
    case EnemyType::GOL_DRAGON:
      return 0x4C;
    case EnemyType::GORAN:
      return 0x52;
    case EnemyType::GORAN_DETONATOR:
      return 0x53;
    case EnemyType::GRASS_ASSASSIN:
      return 0x0C;
    case EnemyType::GUIL_SHARK:
      return 0x12;
    case EnemyType::HALLO_RAPPY:
      return 0x50;
    case EnemyType::HIDOOM:
      return 0x17;
    case EnemyType::HILDEBEAR:
      return 0x01;
    case EnemyType::HILDEBLUE:
      return 0x02;
    case EnemyType::ILL_GILL:
      return 0x52;
    case EnemyType::KONDRIEU:
      return 0x5B;
    case EnemyType::LA_DIMENIAN:
      return 0x2A;
    case EnemyType::LOVE_RAPPY:
      return 0x33;
    case EnemyType::MERICAROL:
      return 0x38;
    case EnemyType::MERICUS:
      return 0x3A;
    case EnemyType::MERIKLE:
      return 0x39;
    case EnemyType::MERILLIA:
      return 0x34;
    case EnemyType::MERILTAS:
      return 0x35;
    case EnemyType::MERISSA_A:
      return 0x46;
    case EnemyType::MERISSA_AA:
      return 0x47;
    case EnemyType::MIGIUM:
      return 0x16;
    case EnemyType::MONEST:
      return 0x04;
    case EnemyType::MORFOS:
      return 0x42;
    case EnemyType::MOTHMANT:
      return 0x03;
    case EnemyType::NANO_DRAGON:
      return 0x0F;
    case EnemyType::NAR_LILY:
      return 0x0E;
    case EnemyType::OLGA_FLOW_2:
      return 0x4E;
    case EnemyType::PAL_SHARK:
      return 0x11;
    case EnemyType::PAN_ARMS:
      return 0x15;
    case EnemyType::PAZUZU:
      return 0x4B;
    case EnemyType::PAZUZU_ALT:
      return 0x4C;
    case EnemyType::POFUILLY_SLIME:
      return 0x13;
    case EnemyType::POUILLY_SLIME:
      return 0x14;
    case EnemyType::POISON_LILY:
      return 0x0D;
    case EnemyType::PYRO_GORAN:
      return 0x54;
    case EnemyType::RAG_RAPPY:
      return 0x05;
    case EnemyType::RECOBOX:
      return 0x43;
    case EnemyType::RECON:
      return 0x44;
    case EnemyType::SAINT_RAPPY:
      return 0x4F;
    case EnemyType::SAINT_MILLION:
      return 0x59;
    case EnemyType::SAND_RAPPY:
      return 0x55;
    case EnemyType::SAND_RAPPY_ALT:
      return 0x56;
    case EnemyType::SATELLITE_LIZARD:
      return 0x44;
    case EnemyType::SATELLITE_LIZARD_ALT:
      return 0x45;
    case EnemyType::SAVAGE_WOLF:
      return 0x07;
    case EnemyType::SHAMBERTIN:
      return 0x5A;
    case EnemyType::SINOW_BEAT:
      return 0x1A;
    case EnemyType::SINOW_BERILL:
      return 0x3E;
    case EnemyType::SINOW_GOLD:
      return 0x1B;
    case EnemyType::SINOW_SPIGELL:
      return 0x3F;
    case EnemyType::SINOW_ZELE:
      return 0x46;
    case EnemyType::SINOW_ZOA:
      return 0x45;
    case EnemyType::SO_DIMENIAN:
      return 0x2B;
    case EnemyType::UL_GIBBON:
      return 0x3B;
    case EnemyType::VOL_OPT_2:
      return 0x2E;
    case EnemyType::YOWIE:
      return 0x42;
    case EnemyType::YOWIE_ALT:
      return 0x43;
    case EnemyType::ZE_BOOTA:
      return 0x4E;
    case EnemyType::ZOL_GIBBON:
      return 0x3C;
    case EnemyType::ZU:
      return 0x49;
    case EnemyType::ZU_ALT:
      return 0x4A;
    default:
      throw runtime_error(string_printf("%s does not have a rare table entry", name_for_enum(enemy_type)));
  }
}

const vector<EnemyType>& enemy_types_for_rare_table_index(Episode episode, uint8_t rt_index) {
  const auto& generate_table = +[](Episode episode) -> vector<vector<EnemyType>> {
    vector<vector<EnemyType>> ret;
    for (size_t z = 0; z < static_cast<size_t>(EnemyType::MAX_ENEMY_TYPE); z++) {
      EnemyType t = static_cast<EnemyType>(z);
      try {
        uint8_t rt_index = rare_table_index_for_enemy_type(t);
        if (enemy_type_valid_for_episode(episode, t)) {
          if (rt_index >= ret.size()) {
            ret.resize(rt_index + 1);
          }
          ret[rt_index].emplace_back(t);
        }
      } catch (const exception&) {
      }
    }
    return ret;
  };

  static array<vector<vector<EnemyType>>, 5> data;
  auto& ret = data.at(static_cast<size_t>(episode));
  if (ret.empty()) {
    ret = generate_table(episode);
  }
  try {
    return ret.at(rt_index);
  } catch (const out_of_range&) {
    static const vector<EnemyType> empty_vec;
    return empty_vec;
  }
}

bool enemy_type_is_rare(EnemyType type) {
  return ((type == EnemyType::HILDEBLUE) ||
      (type == EnemyType::AL_RAPPY) ||
      (type == EnemyType::NAR_LILY) ||
      (type == EnemyType::POUILLY_SLIME) ||
      (type == EnemyType::MERISSA_AA) ||
      (type == EnemyType::PAZUZU_ALT) ||
      (type == EnemyType::DORPHON_ECLAIR) ||
      (type == EnemyType::KONDRIEU));
}
