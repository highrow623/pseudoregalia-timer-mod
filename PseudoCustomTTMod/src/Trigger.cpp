#pragma once

#include "Trigger.hpp"

#include <optional>
#include <unordered_map>

#include "Event.hpp"
#include "Logger.hpp"

namespace
{
    typedef std::unordered_map<std::wstring, std::unordered_map<std::wstring, Event::Event>> EventMap;
    const EventMap small_key_events = {
        {L"ZONE_Exterior", {
            {L"BP_GenericKey_C_2", Event::Event::SmallKeyBaileyBuilding},
        }},
        {L"ZONE_LowerCastle", {
            {L"BP_GenericKey_C_1", Event::Event::SmallKeyCastleTallRoom},
            {L"BP_GenericKey_C_2", Event::Event::SmallKeyCastleCrossroads},
        }},
        {L"ZONE_Dungeon", {
            {L"BP_GenericKey_C_1", Event::Event::SmallKeyDungeonStrongEyes},
            {L"BP_GenericKey_C_2", Event::Event::SmallKeyDungeonRafters},
        }},
        {L"Zone_Caves", {
            {L"BP_GenericKey_C_2", Event::Event::SmallKeyUnderbellyBigRoom},
        }},
        {L"Zone_Upper", {
            {L"BP_GenericKey_C_1", Event::Event::SmallKeyKeepLeverRoom},
        }},
    };

    const EventMap hp_events = {
        {L"Zone_Library", {
            {L"BP_HealthPiece_C_1", Event::Event::HealthPieceLibraryBack},
            {L"BP_HealthPiece_C_3", Event::Event::HealthPieceLibraryLocked},
        }},
        {L"ZONE_LowerCastle", {
            {L"BP_HealthPiece_C_2", Event::Event::HealthPieceCastleCrawlers},
            {L"BP_HealthPiece_C_3", Event::Event::HealthPieceCastleCorner},
            {L"BP_HealthPiece_C_4", Event::Event::HealthPieceCastleBalcony},
            {L"BP_HealthPiece_C_5", Event::Event::HealthPieceCastleRiver},
            {L"BP_HealthPiece_C_9", Event::Event::HealthPieceCastleScythes},
        }},
        {L"ZONE_Exterior", {
            {L"BP_HealthPiece_C_1", Event::Event::HealthPieceBaileySteeple},
        }},
        {L"Zone_Upper", {
            {L"BP_HealthPiece_C_1", Event::Event::HealthPieceKeepLocked},
        }},
        {L"Zone_Caves", {
            {L"BP_HealthPiece_C_1", Event::Event::HealthPieceUnderbellyRafters},
            {L"BP_HealthPiece_C_2", Event::Event::HealthPieceUnderbellyBuilding},
            {L"BP_HealthPiece_C_4", Event::Event::HealthPieceUnderbellyPillar},
        }},
        {L"Zone_Theatre", {
            {L"BP_HealthPiece_C_1", Event::Event::HealthPieceTheatreBoxes},
            {L"BP_HealthPiece_C_3", Event::Event::HealthPieceTheatreAuditorium},
        }},
        {L"ZONE_Dungeon", {
            {L"BP_HealthPiece_C_1", Event::Event::HealthPieceDungeonAlcove},
            {L"BP_HealthPiece_C_3", Event::Event::HealthPieceDungeonPoles},
        }},
    };

    const EventMap upgrade_events = {
        {L"Zone_Library", {
            {L"BP_UpgradeBase_C_1", Event::Event::AbilitySunGreaves},
            {L"BP_UpgradeBase_C_2", Event::Event::AttireSweater},
            {L"BP_UpgradeBase_C_6", Event::Event::AspectClearMindLibrary},
        }},
        {L"ZONE_LowerCastle", {
            {L"BP_UpgradeBase_C_2", Event::Event::AbilityIndignation},
            {L"BP_UpgradeBase_C_3", Event::Event::AspectPilgrimage},
            {L"BP_UpgradeBase_C_4", Event::Event::AspectGoodGracesCastle},
            {L"BP_UpgradeBase_C_5", Event::Event::AspectClearMindCastle},
            {L"BP_UpgradeBase_C_6", Event::Event::Memento},
            {L"BP_UpgradeBase_C_7", Event::Event::AttireProfessionalism},
        }},
        {L"ZONE_Exterior", {
            {L"BP_UpgradeBase_C_1", Event::Event::AbilitySolarWind},
            {L"BP_UpgradeBase_C_2", Event::Event::AspectEmpathyBailey},
            {L"BP_UpgradeBase_C_3", Event::Event::AttireChivalry},
        }},
        {L"Zone_Upper", {
            {L"BP_UpgradeBase_C_1", Event::Event::AbilitySunsetter},
            {L"BP_UpgradeBase_C_2", Event::Event::AbilityStrikebreak},
            {L"BP_UpgradeBase_C_3", Event::Event::AspectClearMindKeep},
            {L"BP_UpgradeBase_C_6", Event::Event::AttireAGuardian},
        }},
        {L"Zone_Caves", {
            {L"BP_UpgradeBase_C_1", Event::Event::AbilityAscendantLight},
            {L"BP_UpgradeBase_C_2", Event::Event::AttireNostalgia},
            {L"BP_UpgradeBase_C_4", Event::Event::AspectMartialProwess},
            {L"BP_UpgradeBase_C_6", Event::Event::AspectHeliacalPower},
        }},
        {L"Zone_Theatre", {
            {L"BP_UpgradeBase_C_1", Event::Event::AbilitySoulCutter},
            {L"BP_UpgradeBase_C_2", Event::Event::AspectAerialFinesse},
            {L"BP_UpgradeBase_C_3", Event::Event::AttireClass},
            {L"BP_UpgradeBase_C_4", Event::Event::AspectEmpathyTheatre},
        }},
        {L"ZONE_Dungeon", {
            {L"BP_UpgradeBase_C_1", Event::Event::AbilityDreamBreaker},
            {L"BP_UpgradeBase_C_2", Event::Event::AbilitySlide},
            {L"BP_UpgradeBase_C_3", Event::Event::AttireDevotion},
            {L"BP_UpgradeBase_C_8", Event::Event::AspectGoodGracesDungeon},
        }},
        {L"Zone_Tower", {
            {L"BP_UpgradeBase_C_1", Event::Event::AbilityClingGem},
            {L"BP_UpgradeBase_C_2", Event::Event::AttireBleedingHeart},
        }},
    };

    const EventMap transition_events = {
        {L"Zone_Library", {
            {L"BP_TransitionZone_C_1", Event::Event::TransitionLibraryToCastle},
        }},
        {L"ZONE_LowerCastle", {
            {L"BP_TransitionZone_C_0", Event::Event::TransitionCastleToTheatrePillar},
            {L"BP_TransitionZone_C_1", Event::Event::TransitionCastleToDungeon},
            {L"BP_TransitionZone_C_2", Event::Event::TransitionCastleToBailey},
            {L"BP_TransitionZone_C_4", Event::Event::TransitionCastleToKeepLocked},
            {L"BP_TransitionZone_C_5", Event::Event::TransitionCastleToKeepSouth},
            {L"BP_TransitionZone_C_6", Event::Event::TransitionCastleToKeepNorth},
            {L"BP_TransitionZone_C_7", Event::Event::TransitionCastleToLibrary},
            {L"BP_TransitionZone_C_8", Event::Event::TransitionCastleToTheatreFront},
        }},
        {L"ZONE_Exterior", {
            {L"BP_TransitionZone_C_1", Event::Event::TransitionBaileyToCastle},
            {L"BP_TransitionZone_C_2", Event::Event::TransitionBaileyToTheatre},
            {L"BP_TransitionZone_C_3", Event::Event::TransitionBaileyToTower},
            {L"BP_TransitionZone_C_5", Event::Event::TransitionBaileyToUnderbelly},
        }},
        {L"Zone_Upper", {
            {L"BP_TransitionZone_C_1", Event::Event::TransitionKeepToCastleSouth},
            {L"BP_TransitionZone_C_2", Event::Event::TransitionKeepToCastleLocked},
            {L"BP_TransitionZone_C_3", Event::Event::TransitionKeepToUnderbelly},
            {L"BP_TransitionZone_C_4", Event::Event::TransitionKeepToTheatre},
            {L"BP_TransitionZone_C_5", Event::Event::TransitionKeepToCastleNorth},
        }},
        {L"Zone_Caves", {
            {L"BP_TransitionZone_C_1", Event::Event::TransitionUnderbellyToBailey},
            {L"BP_TransitionZone_C_2", Event::Event::TransitionUnderbellyToDungeon},
            {L"BP_TransitionZone_C_3", Event::Event::TransitionUnderbellyToKeep},
        }},
        {L"Zone_Theatre", {
            {L"BP_TransitionZone_C_1", Event::Event::TransitionTheatreToCastleNorthwest},
            {L"BP_TransitionZone_C_2", Event::Event::TransitionTheatreToKeep},
            {L"BP_TransitionZone_C_3", Event::Event::TransitionTheatreToBailey},
            {L"BP_TransitionZone_C_4", Event::Event::TransitionTheatreToDungeon},
            {L"BP_TransitionZone_C_6", Event::Event::TransitionTheatreToCastleWest},
        }},
        {L"ZONE_Dungeon", {
            {L"BP_TransitionZone_C_1", Event::Event::TransitionDungeonToCastle},
            {L"BP_TransitionZone_C_2", Event::Event::TransitionDungeonToUnderbelly},
            {L"BP_TransitionZone_C_3", Event::Event::TransitionDungeonToTheatre},
        }},
        {L"Zone_Tower", {
            {L"BP_TransitionZone_C_1", Event::Event::TransitionTowerToBailey},
            {L"BP_TransitionZone_C_2", Event::Event::TransitionTowerToChambers},
        }},
        {L"Zone_PrincessChambers", {
            {L"BP_TransitionZone_C_1", Event::Event::TransitionChambersToTower},
        }},
    };

    std::unordered_map<std::wstring, std::unordered_map<int32_t, Event::Event>> room_events = {
        {L"ZONE_Exterior", {
            {0, Event::Event::RoomBailey0},
            {1, Event::Event::RoomBailey1},
            {2, Event::Event::RoomBailey2},
            {3, Event::Event::RoomBailey3},
        }},
        {L"Zone_Caves", {
            {0, Event::Event::RoomUnderbelly0},
            {1, Event::Event::RoomUnderbelly1},
            {2, Event::Event::RoomUnderbelly2},
            {3, Event::Event::RoomUnderbelly3},
            {4, Event::Event::RoomUnderbelly4},
            {5, Event::Event::RoomUnderbelly5},
            {6, Event::Event::RoomUnderbelly6},
            {7, Event::Event::RoomUnderbelly7},
            {8, Event::Event::RoomUnderbelly8},
            {9, Event::Event::RoomUnderbelly9},
            {10, Event::Event::RoomUnderbelly10},
            {11, Event::Event::RoomUnderbelly11},
            {12, Event::Event::RoomUnderbelly12},
            {13, Event::Event::RoomUnderbelly13},
            {14, Event::Event::RoomUnderbelly14},
            {15, Event::Event::RoomUnderbelly15},
            {16, Event::Event::RoomUnderbelly16},
            {17, Event::Event::RoomUnderbelly17},
            {18, Event::Event::RoomUnderbelly18},
            {19, Event::Event::RoomUnderbelly19},
            {20, Event::Event::RoomUnderbelly20},
            {21, Event::Event::RoomUnderbelly21},
            {22, Event::Event::RoomUnderbelly22},
            {23, Event::Event::RoomUnderbelly23},
            {24, Event::Event::RoomUnderbelly24},
            {25, Event::Event::RoomUnderbelly25},
            {26, Event::Event::RoomUnderbelly26},
            {27, Event::Event::RoomUnderbelly27},
            {28, Event::Event::RoomUnderbelly28},
            {29, Event::Event::RoomUnderbelly29},
            {30, Event::Event::RoomUnderbelly30},
            {31, Event::Event::RoomUnderbelly31},
            {32, Event::Event::RoomUnderbelly32},
            {33, Event::Event::RoomUnderbelly33},
            {34, Event::Event::RoomUnderbelly34},
            {35, Event::Event::RoomUnderbelly35},
            {36, Event::Event::RoomUnderbelly36},
        }},
        {L"ZONE_Dungeon", {
            {0, Event::Event::RoomDungeon0},
            {1, Event::Event::RoomDungeon1},
            {2, Event::Event::RoomDungeon2},
            {3, Event::Event::RoomDungeon3},
            {4, Event::Event::RoomDungeon4},
            {5, Event::Event::RoomDungeon5},
            {6, Event::Event::RoomDungeon6},
            {7, Event::Event::RoomDungeon7},
            {8, Event::Event::RoomDungeon8},
            {9, Event::Event::RoomDungeon9},
            {10, Event::Event::RoomDungeon10},
            {11, Event::Event::RoomDungeon11},
            {12, Event::Event::RoomDungeon12},
            {13, Event::Event::RoomDungeon13},
            {14, Event::Event::RoomDungeon14},
            {15, Event::Event::RoomDungeon15},
            {16, Event::Event::RoomDungeon16},
            {17, Event::Event::RoomDungeon17},
            {18, Event::Event::RoomDungeon18},
            {19, Event::Event::RoomDungeon19},
            {20, Event::Event::RoomDungeon20},
            {21, Event::Event::RoomDungeon21},
            {22, Event::Event::RoomDungeon22},
            {23, Event::Event::RoomDungeon23},
        }},
        {L"Zone_Upper", {
            {0, Event::Event::RoomKeep0},
            {1, Event::Event::RoomKeep1},
            {2, Event::Event::RoomKeep2},
            {3, Event::Event::RoomKeep3},
            {4, Event::Event::RoomKeep4},
            {5, Event::Event::RoomKeep5},
            {6, Event::Event::RoomKeep6},
            {7, Event::Event::RoomKeep7},
            {8, Event::Event::RoomKeep8},
            {9, Event::Event::RoomKeep9},
            {10, Event::Event::RoomKeep10},
            {11, Event::Event::RoomKeep11},
            {12, Event::Event::RoomKeep12},
            {13, Event::Event::RoomKeep13},
            {14, Event::Event::RoomKeep14},
            {15, Event::Event::RoomKeep15},
            {16, Event::Event::RoomKeep16},
            {17, Event::Event::RoomKeep17},
            {18, Event::Event::RoomKeep18},
            {19, Event::Event::RoomKeep19},
            {20, Event::Event::RoomKeep20},
            {21, Event::Event::RoomKeep21},
            {22, Event::Event::RoomKeep22},
            {23, Event::Event::RoomKeep23},
            {24, Event::Event::RoomKeep24},
        }},
        {L"Zone_Library", {
            {0, Event::Event::RoomLibrary0},
            {1, Event::Event::RoomLibrary1},
            {2, Event::Event::RoomLibrary2},
            {3, Event::Event::RoomLibrary3},
            {4, Event::Event::RoomLibrary4},
            {5, Event::Event::RoomLibrary5},
            {6, Event::Event::RoomLibrary6},
            {7, Event::Event::RoomLibrary7},
            {8, Event::Event::RoomLibrary8},
            {9, Event::Event::RoomLibrary9},
            {10, Event::Event::RoomLibrary10},
        }},
        {L"ZONE_LowerCastle", {
            {0, Event::Event::RoomCastle0},
            {1, Event::Event::RoomCastle1},
            {2, Event::Event::RoomCastle2},
            {3, Event::Event::RoomCastle3},
            {4, Event::Event::RoomCastle4},
            {5, Event::Event::RoomCastle5},
            {6, Event::Event::RoomCastle6},
            {7, Event::Event::RoomCastle7},
            {8, Event::Event::RoomCastle8},
            {9, Event::Event::RoomCastle9},
            {10, Event::Event::RoomCastle10},
            {11, Event::Event::RoomCastle11},
            {12, Event::Event::RoomCastle12},
            {13, Event::Event::RoomCastle13},
            {14, Event::Event::RoomCastle14},
            {15, Event::Event::RoomCastle15},
            {16, Event::Event::RoomCastle16},
            {17, Event::Event::RoomCastle17},
            {18, Event::Event::RoomCastle18},
            {19, Event::Event::RoomCastle19},
            {20, Event::Event::RoomCastle20},
            {21, Event::Event::RoomCastle21},
            {22, Event::Event::RoomCastle22},
            {23, Event::Event::RoomCastle23},
            {24, Event::Event::RoomCastle24},
            {25, Event::Event::RoomCastle25},
            {26, Event::Event::RoomCastle26},
            {27, Event::Event::RoomCastle27},
            {28, Event::Event::RoomCastle28},
            {29, Event::Event::RoomCastle29},
            {30, Event::Event::RoomCastle30},
            {31, Event::Event::RoomCastle31},
        }},
        {L"Zone_Theatre", {
            {0, Event::Event::RoomTheatre0},
            {1, Event::Event::RoomTheatre1},
            {2, Event::Event::RoomTheatre2},
            {3, Event::Event::RoomTheatre3},
            {4, Event::Event::RoomTheatre4},
            {5, Event::Event::RoomTheatre5},
            {6, Event::Event::RoomTheatre6},
            {7, Event::Event::RoomTheatre7},
            {8, Event::Event::RoomTheatre8},
            {9, Event::Event::RoomTheatre9},
            {10, Event::Event::RoomTheatre10},
            {11, Event::Event::RoomTheatre11},
            {12, Event::Event::RoomTheatre12},
            {13, Event::Event::RoomTheatre13},
            {14, Event::Event::RoomTheatre14},
            {15, Event::Event::RoomTheatre15},
            {16, Event::Event::RoomTheatre16},
            {17, Event::Event::RoomTheatre17},
            {18, Event::Event::RoomTheatre18},
            {19, Event::Event::RoomTheatre19},
            {20, Event::Event::RoomTheatre20},
            {21, Event::Event::RoomTheatre21},
            {22, Event::Event::RoomTheatre22},
            {23, Event::Event::RoomTheatre23},
            {24, Event::Event::RoomTheatre24},
        }},
        {L"Zone_Tower", {
            {0, Event::Event::RoomTower0},
            {1, Event::Event::RoomTower1},
            {2, Event::Event::RoomTower2},
            {4, Event::Event::RoomTower4},
            {5, Event::Event::RoomTower5},
            {6, Event::Event::RoomTower6},
        }},
    };

    std::wstring current_zone = L"NONE";
    std::optional<int32_t> current_room = {};

    typedef std::optional<Event::Event> QueuedEvent;
    QueuedEvent queued_small_key_event = {};
    QueuedEvent queued_hp_event = {};
    QueuedEvent queued_upgrade_event = {};
    QueuedEvent queued_transition_event = {};
}

void Trigger::EnterZone(std::wstring zone)
{
    if (current_zone == L"TitleScreen" && zone == L"ZONE_Dungeon")
    {
        Event::Triggered(Event::Event::StartGame);
    }
    if (queued_transition_event)
    {
        Event::Triggered(*queued_transition_event);
        queued_transition_event.reset();
    }
    current_zone = zone;
    current_room.reset();
}

void Trigger::GetMajorKey(int32_t key_id)
{
    switch (key_id) {
    case 1:
        Event::Triggered(Event::Event::MajorKeyBailey);
        return;
    case 2:
        Event::Triggered(Event::Event::MajorKeyUnderbelly);
        return;
    case 3:
        Event::Triggered(Event::Event::MajorKeyTower);
        return;
    case 4:
        Event::Triggered(Event::Event::MajorKeyKeep);
        return;
    case 5:
        Event::Triggered(Event::Event::MajorKeyTheatre);
        return;
    }
    Log("updateImportantKey: unknown key " + std::to_string(key_id), LogType::Warning);
}

void Trigger::TouchSmallKey(std::wstring key_name)
{
    if (!small_key_events.contains(current_zone))
    {
        Log(L"touched small key, but there are no small keys in " + current_zone, LogType::Warning);
        return;
    }

    const auto& zone_key_events = small_key_events.at(current_zone);
    if (!zone_key_events.contains(key_name))
    {
        Log(L"touched small key, but there is no small key " + key_name + L" in " + current_zone, LogType::Warning);
        return;
    }

    queued_small_key_event = zone_key_events.at(key_name);
}

void Trigger::GetSmallKey()
{
    if (queued_small_key_event)
    {
        Event::Triggered(*queued_small_key_event);
        queued_small_key_event.reset();
    }
}

void Trigger::TouchHealthPiece(std::wstring hp_name)
{
    if (!hp_events.contains(current_zone))
    {
        Log(L"touched hp, but there are no hps in " + current_zone, LogType::Warning);
        return;
    }

    const auto& zone_hp_events = hp_events.at(current_zone);
    if (!zone_hp_events.contains(hp_name))
    {
        Log(L"touched hp, but there is no hp " + hp_name + L" in " + current_zone, LogType::Warning);
        return;
    }

    queued_hp_event = zone_hp_events.at(hp_name);
}

void Trigger::GetHealthPiece()
{
    if (queued_hp_event)
    {
        Event::Triggered(*queued_hp_event);
        queued_hp_event.reset();
    }
}

void Trigger::TouchUpgrade(std::wstring upgrade_name)
{
    if (!upgrade_events.contains(current_zone))
    {
        Log(L"touched upgrade, but there are no upgrades in " + current_zone, LogType::Warning);
        return;
    }

    const auto& zone_upgrade_events = upgrade_events.at(current_zone);
    if (!zone_upgrade_events.contains(upgrade_name))
    {
        Log(L"touched upgrade, but there is no upgrade " + upgrade_name + L" in " + current_zone, LogType::Warning);
        return;
    }

    queued_upgrade_event = zone_upgrade_events.at(upgrade_name);
}

void Trigger::GetUpgrade()
{
    if (queued_upgrade_event)
    {
        Event::Triggered(*queued_upgrade_event);
        queued_upgrade_event.reset();
    }
}

void Trigger::TouchTransition(std::wstring transition_name)
{
    if (!transition_events.contains(current_zone))
    {
        Log(L"touched transition, but there are no transitions in " + current_zone, LogType::Warning);
        return;
    }

    const auto& zone_transition_events = transition_events.at(current_zone);
    if (!zone_transition_events.contains(transition_name))
    {
        Log(L"touched transition, but there is no transition " + transition_name + L" in " + current_zone,
            LogType::Warning);
        return;
    }

    queued_transition_event = zone_transition_events.at(transition_name);
}

void Trigger::Reset()
{
    queued_small_key_event.reset();
    queued_hp_event.reset();
    queued_upgrade_event.reset();
    queued_transition_event.reset();
}

void Trigger::SetRoom(int32_t room_id)
{
    if (!current_room)
    {
        current_room = room_id;
        return;
    }
    if (*current_room == room_id) return;

    current_room = room_id;
    if (!room_events.contains(current_zone))
    {
        Log(L"active room changed, but there is no room data for " + current_zone, LogType::Warning);
        return;
    }

    const auto& zone_room_events = room_events.at(current_zone);
    if (!zone_room_events.contains(room_id))
    {
        Log(L"active room changed, but there is no room data for " + std::to_wstring(room_id) + L" in " + current_zone,
            LogType::Warning);
        return;
    }

    Event::Triggered(zone_room_events.at(room_id));
}
