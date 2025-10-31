#pragma once

#include "Event.hpp"

#include <chrono>
#include <map>
#include <optional>
#include <string>

#include "Unreal/FText.hpp"

#include "Logger.hpp"

namespace
{
    const std::map<Event::Event, std::string> event_to_string = {
        {Event::Event::StartGame, "Start Game"},

        {Event::Event::MajorKeyBailey, "Bailey Major Key"},
        {Event::Event::MajorKeyUnderbelly, "Underbelly Major Key"},
        {Event::Event::MajorKeyTower, "Tower Major Key"},
        {Event::Event::MajorKeyKeep, "Keep Major Key"},
        {Event::Event::MajorKeyTheatre, "Theatre Major Key"},

        {Event::Event::SmallKeyDungeonRafters, "Dungeon Rafters Small Key"},
        {Event::Event::SmallKeyDungeonStrongEyes, "Dungeon Strong Eyes Small Key"},
        {Event::Event::SmallKeyCastleCrossroads, "Castle Crossroads Small Key"},
        {Event::Event::SmallKeyCastleTallRoom, "Castle Tall Room Small Key"},
        {Event::Event::SmallKeyUnderbellyBigRoom, "Underbelly Big Room Small Key"},
        {Event::Event::SmallKeyKeepLeverRoom, "Keep Lever Room Small Key"},
        {Event::Event::SmallKeyBaileyBuilding, "Bailey Building Small Key"},

        {Event::Event::HealthPieceLibraryBack, "Library Back HP"},
        {Event::Event::HealthPieceLibraryLocked, "Library Locked HP"},
        {Event::Event::HealthPieceCastleCorner, "Castle Corner HP"},
        {Event::Event::HealthPieceCastleBalcony, "Castle Balcony HP"},
        {Event::Event::HealthPieceCastleCrawlers, "Castle Crawlers HP"},
        {Event::Event::HealthPieceCastleScythes, "Castle Scythes HP"},
        {Event::Event::HealthPieceCastleRiver, "Castle River HP"},
        {Event::Event::HealthPieceBaileySteeple, "Bailey Steeple HP"},
        {Event::Event::HealthPieceKeepLocked, "Keep Locked HP"},
        {Event::Event::HealthPieceUnderbellyRafters, "Underbelly Rafters HP"},
        {Event::Event::HealthPieceUnderbellyPillar, "Underbelly Pillar HP"},
        {Event::Event::HealthPieceUnderbellyBuilding, "Underbelly Building HP"},
        {Event::Event::HealthPieceTheatreAuditorium, "Theatre Auditorium HP"},
        {Event::Event::HealthPieceTheatreBoxes, "Theatre Boxes HP"},
        {Event::Event::HealthPieceDungeonAlcove, "Dungeon Alcove HP"},
        {Event::Event::HealthPieceDungeonPoles, "Dungeon Poles HP"},

        {Event::Event::AbilityDreamBreaker, "Dream Breaker"},
        {Event::Event::AbilityIndignation, "Indignation"},
        {Event::Event::AbilitySlide, "Slide"},
        {Event::Event::AbilitySolarWind, "Solar Wind"},
        {Event::Event::AbilitySunGreaves, "Sun Greaves"},
        {Event::Event::AbilitySunsetter, "Sunsetter"},
        {Event::Event::AbilityClingGem, "Cling Gem"},
        {Event::Event::AbilityAscendantLight, "Ascendant Light"},
        {Event::Event::AbilityStrikebreak, "Strikebreak"},
        {Event::Event::AbilitySoulCutter, "Soul Cutter"},

        {Event::Event::AspectClearMindLibrary, "Clear Mind (Library)"},
        {Event::Event::AspectClearMindKeep, "Clear Mind (Keep)"},
        {Event::Event::AspectClearMindCastle, "Clear Mind (Castle)"},
        {Event::Event::AspectEmpathyBailey, "Empathy (Bailey)"},
        {Event::Event::AspectEmpathyTheatre, "Empathy (Theatre)"},
        {Event::Event::AspectGoodGracesCastle, "Good Graces (Castle)"},
        {Event::Event::AspectGoodGracesDungeon, "Good Graces (Dungeon)"},
        {Event::Event::AspectMartialProwess, "Martial Prowess"},
        {Event::Event::AspectPilgrimage, "Pilgrimage"},
        {Event::Event::AspectAerialFinesse, "Aerial Finesse"},
        {Event::Event::AspectHeliacalPower, "Heliacal Power"},

        {Event::Event::Memento, "Memento"},

        {Event::Event::AttireProfessionalism, "Professionalism"},
        {Event::Event::AttireAGuardian, "A Guardian"},
        {Event::Event::AttireChivalry, "Chivalry"},
        {Event::Event::AttireBleedingHeart, "Bleeding Heart"},
        {Event::Event::AttireNostalgia, "Nostalgia"},
        {Event::Event::AttireDevotion, "Devotion"},
        {Event::Event::AttireClass, "Class"},
        {Event::Event::AttireSweater, "Sweater"},

        {Event::Event::TransitionDungeonToCastle, "Dungeon -> Castle"},
        {Event::Event::TransitionDungeonToUnderbelly, "Dungeon -> Underbelly"},
        {Event::Event::TransitionDungeonToTheatre, "Dungeon -> Theatre"},
        {Event::Event::TransitionCastleToDungeon, "Castle -> Dungeon"},
        {Event::Event::TransitionCastleToBailey, "Castle -> Bailey"},
        {Event::Event::TransitionCastleToKeepSouth, "Castle -> Keep (South)"},
        {Event::Event::TransitionCastleToKeepLocked, "Castle -> Keep (Locked)"},
        {Event::Event::TransitionCastleToKeepNorth, "Castle -> Keep (North)"},
        {Event::Event::TransitionCastleToLibrary, "Castle -> Library"},
        {Event::Event::TransitionCastleToTheatrePillar, "Castle -> Theatre (Pillar)"},
        {Event::Event::TransitionCastleToTheatreFront, "Castle -> Theatre (Front)"},
        {Event::Event::TransitionLibraryToCastle, "Library -> Castle"},
        {Event::Event::TransitionBaileyToCastle, "Bailey -> Castle"},
        {Event::Event::TransitionBaileyToUnderbelly, "Bailey -> Underbelly"},
        {Event::Event::TransitionBaileyToTower, "Bailey -> Tower"},
        {Event::Event::TransitionBaileyToTheatre, "Bailey -> Theatre"},
        {Event::Event::TransitionKeepToCastleSouth, "Keep -> Castle (South)"},
        {Event::Event::TransitionKeepToCastleLocked, "Keep -> Castle (Locked)"},
        {Event::Event::TransitionKeepToCastleNorth, "Keep -> Castle (North)"},
        {Event::Event::TransitionKeepToUnderbelly, "Keep -> Underbelly"},
        {Event::Event::TransitionKeepToTheatre, "Keep -> Theatre"},
        {Event::Event::TransitionUnderbellyToDungeon, "Underbelly -> Dungeon"},
        {Event::Event::TransitionUnderbellyToBailey, "Underbelly -> Bailey"},
        {Event::Event::TransitionUnderbellyToKeep, "Underbelly -> Keep"},
        {Event::Event::TransitionTheatreToDungeon, "Theatre -> Dungeon"},
        {Event::Event::TransitionTheatreToCastleWest, "Theatre -> Castle (West)"},
        {Event::Event::TransitionTheatreToCastleNorthwest, "Theatre -> Castle (Northwest)"},
        {Event::Event::TransitionTheatreToBailey, "Theatre -> Bailey"},
        {Event::Event::TransitionTheatreToKeep, "Theatre -> Keep"},
        {Event::Event::TransitionTowerToBailey, "Tower -> Bailey"},
        {Event::Event::TransitionTowerToChambers, "Tower -> Chambers"},
        {Event::Event::TransitionChambersToTower, "Chambers -> Tower"},

        {Event::Event::FinishGame, "Finish Game"},
    };

    std::optional<Event::Event> start_event = Event::Event::AspectPilgrimage;
    std::optional<Event::Event> end_event = Event::Event::AspectGoodGracesCastle;
    std::optional<std::chrono::steady_clock::time_point> start_time = {};
    std::optional<int64_t> elapsed_millis = {};
    std::optional<int64_t> pb_millis = {};
    std::optional<int64_t> target_millis = {};
    bool timer_running = false;

    std::string MillisToString(int64_t);
}

void Event::Triggered(Event event)
{
    if (!event_to_string.contains(event))
    {
        Log("unknown event triggered", LogType::Warning);
        return;
    }
    Log("e: " + event_to_string.at(event));

    if (!start_time && start_event && *start_event == event && end_event)
    {
        Log("starting timer");
        start_time = std::chrono::steady_clock::now();
        elapsed_millis.reset();
        if (pb_millis)
        {
            target_millis = pb_millis;
        }
    }

    if (start_time && end_event && *end_event == event)
    {
        elapsed_millis = (std::chrono::steady_clock::now() - *start_time).count() / 1000000LL;
        Log("ending timer; elapsed millis: " + MillisToString(*elapsed_millis));
        start_time.reset();
        if (!pb_millis || *elapsed_millis < *pb_millis)
        {
            pb_millis = elapsed_millis;
        }
    }
}

void Event::HandleTimer(RC::Unreal::UObject* manager_obj)
{
    if (timer_running && elapsed_millis)
    {
        // segment has finished
        timer_running = false;
        std::wstring elapsed_str = Logger::ToWide(MillisToString(*elapsed_millis));

        auto widget = *manager_obj->GetValuePtrByPropertyName<RC::Unreal::UObject*>(L"TimerWidgetRef");
        auto time = widget->GetValuePtrByPropertyName<RC::Unreal::FText>(L"Time");
        time->SetString(RC::Unreal::FString(elapsed_str.c_str()));

        if (target_millis)
        {
            if (*elapsed_millis > *target_millis)
            {
                auto diff_millis = *elapsed_millis - *target_millis;
                auto diff_str = L"+" + Logger::ToWide(MillisToString(diff_millis));

                auto diff_pos = widget->GetValuePtrByPropertyName<RC::Unreal::FText>(L"DiffPos");
                diff_pos->SetString(RC::Unreal::FString(diff_str.c_str()));
            }
            else
            {
                auto diff_millis = *target_millis - *elapsed_millis;
                auto diff_str = L"-" + Logger::ToWide(MillisToString(diff_millis));

                auto diff_neg = widget->GetValuePtrByPropertyName<RC::Unreal::FText>(L"DiffNeg");
                diff_neg->SetString(RC::Unreal::FString(diff_str.c_str()));
            }
        }
    }
    else if (!timer_running && start_time)
    {
        // timer not initialized
        timer_running = true;
        auto current_millis = (std::chrono::steady_clock::now() - *start_time).count() / 1000000LL;
        std::wstring elapsed_str = Logger::ToWide(MillisToString(current_millis));

        auto widget = *manager_obj->GetValuePtrByPropertyName<RC::Unreal::UObject*>(L"TimerWidgetRef");
        auto time = widget->GetValuePtrByPropertyName<RC::Unreal::FText>(L"Time");
        time->SetString(RC::Unreal::FString(elapsed_str.c_str()));
        if (target_millis)
        {
            auto target_str = Logger::ToWide(MillisToString(*target_millis));
            auto target = widget->GetValuePtrByPropertyName<RC::Unreal::FText>(L"Target");
            target->SetString(RC::Unreal::FString(target_str.c_str()));
        }
    }
    else if (start_time)
    {
        // timer running and already initialized
        auto current_millis = (std::chrono::steady_clock::now() - *start_time).count() / 1000000LL;
        std::wstring elapsed_str = Logger::ToWide(MillisToString(current_millis));

        auto widget = *manager_obj->GetValuePtrByPropertyName<RC::Unreal::UObject*>(L"TimerWidgetRef");
        auto time = widget->GetValuePtrByPropertyName<RC::Unreal::FText>(L"Time");
        time->SetString(RC::Unreal::FString(elapsed_str.c_str()));

        if (target_millis && current_millis > *target_millis)
        {
            auto diff_millis = current_millis - *target_millis;
            auto diff_str = L"+" + Logger::ToWide(MillisToString(diff_millis));

            auto diff_pos = widget->GetValuePtrByPropertyName<RC::Unreal::FText>(L"DiffPos");
            diff_pos->SetString(RC::Unreal::FString(diff_str.c_str()));
        }
    }
}

void Event::Reset()
{
    if (start_time)
    {
        start_time.reset();
        elapsed_millis.reset();
        target_millis.reset();
        timer_running = false;
        Log("timer reset");
    }
}

namespace
{

std::string MillisToString(int64_t time_millis)
{
    int64_t millis = time_millis % 1000;
    int64_t time_seconds = time_millis / 1000;
    int64_t seconds = time_seconds % 60;
    int64_t time_minutes = time_seconds / 60;
    int64_t minutes = time_minutes % 60;
    int64_t hours = time_minutes / 60;

    std::string display_time;
    if (hours)
    {
        display_time += std::to_string(hours) + ":";
        if (minutes < 10)
        {
            display_time += "0";
        }
    }
    if (hours || minutes)
    {
        display_time += std::to_string(minutes) + ":";
        if (seconds < 10)
        {
            display_time += "0";
        }
    }
    display_time += std::to_string(seconds) + ".";
    if (millis < 10)
    {
        display_time += "00";
    }
    else if (millis < 100)
    {
        display_time += "0";
    }
    display_time += std::to_string(millis);
    return display_time;
}

} // namespace
