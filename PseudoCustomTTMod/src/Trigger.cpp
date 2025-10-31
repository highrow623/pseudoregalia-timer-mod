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

    std::wstring current_zone = L"NONE";

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
        Log(L"touched transition, but there is no traisition " + transition_name + L" in " + current_zone,
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