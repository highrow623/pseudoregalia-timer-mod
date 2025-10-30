#pragma once

#include "Trigger.hpp"

#include <optional>
#include <unordered_map>

#include "Event.hpp"
#include "Logger.hpp"

namespace
{
    const std::unordered_map<std::wstring, std::unordered_map<std::wstring, Event::Event>> small_key_events = {
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

    std::wstring current_zone = L"NONE";
    std::optional<Event::Event> queued_small_key_event = {};
}

void Trigger::EnterZone(std::wstring zone)
{
    Log(L"entered zone " + zone);
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
