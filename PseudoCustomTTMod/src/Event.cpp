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

        {Event::Event::RoomBailey0, "Enter Bailey 0"},
        {Event::Event::RoomBailey1, "Enter Bailey 1"},
        {Event::Event::RoomBailey2, "Enter Bailey 2"},
        {Event::Event::RoomBailey3, "Enter Bailey 3"},
        {Event::Event::RoomUnderbelly0, "Enter Underbelly 0"},
        {Event::Event::RoomUnderbelly1, "Enter Underbelly 1"},
        {Event::Event::RoomUnderbelly2, "Enter Underbelly 2"},
        {Event::Event::RoomUnderbelly3, "Enter Underbelly 3"},
        {Event::Event::RoomUnderbelly4, "Enter Underbelly 4"},
        {Event::Event::RoomUnderbelly5, "Enter Underbelly 5"},
        {Event::Event::RoomUnderbelly6, "Enter Underbelly 6"},
        {Event::Event::RoomUnderbelly7, "Enter Underbelly 7"},
        {Event::Event::RoomUnderbelly8, "Enter Underbelly 8"},
        {Event::Event::RoomUnderbelly9, "Enter Underbelly 9"},
        {Event::Event::RoomUnderbelly10, "Enter Underbelly 10"},
        {Event::Event::RoomUnderbelly11, "Enter Underbelly 11"},
        {Event::Event::RoomUnderbelly12, "Enter Underbelly 12"},
        {Event::Event::RoomUnderbelly13, "Enter Underbelly 13"},
        {Event::Event::RoomUnderbelly14, "Enter Underbelly 14"},
        {Event::Event::RoomUnderbelly15, "Enter Underbelly 15"},
        {Event::Event::RoomUnderbelly16, "Enter Underbelly 16"},
        {Event::Event::RoomUnderbelly17, "Enter Underbelly 17"},
        {Event::Event::RoomUnderbelly18, "Enter Underbelly 18"},
        {Event::Event::RoomUnderbelly19, "Enter Underbelly 19"},
        {Event::Event::RoomUnderbelly20, "Enter Underbelly 20"},
        {Event::Event::RoomUnderbelly21, "Enter Underbelly 21"},
        {Event::Event::RoomUnderbelly22, "Enter Underbelly 22"},
        {Event::Event::RoomUnderbelly23, "Enter Underbelly 23"},
        {Event::Event::RoomUnderbelly24, "Enter Underbelly 24"},
        {Event::Event::RoomUnderbelly25, "Enter Underbelly 25"},
        {Event::Event::RoomUnderbelly26, "Enter Underbelly 26"},
        {Event::Event::RoomUnderbelly27, "Enter Underbelly 27"},
        {Event::Event::RoomUnderbelly28, "Enter Underbelly 28"},
        {Event::Event::RoomUnderbelly29, "Enter Underbelly 29"},
        {Event::Event::RoomUnderbelly30, "Enter Underbelly 30"},
        {Event::Event::RoomUnderbelly31, "Enter Underbelly 31"},
        {Event::Event::RoomUnderbelly32, "Enter Underbelly 32"},
        {Event::Event::RoomUnderbelly33, "Enter Underbelly 33"},
        {Event::Event::RoomUnderbelly34, "Enter Underbelly 34"},
        {Event::Event::RoomUnderbelly35, "Enter Underbelly 35"},
        {Event::Event::RoomUnderbelly36, "Enter Underbelly 36"},
        {Event::Event::RoomDungeon0, "Enter Dungeon 0"},
        {Event::Event::RoomDungeon1, "Enter Dungeon 1"},
        {Event::Event::RoomDungeon2, "Enter Dungeon 2"},
        {Event::Event::RoomDungeon3, "Enter Dungeon 3"},
        {Event::Event::RoomDungeon4, "Enter Dungeon 4"},
        {Event::Event::RoomDungeon5, "Enter Dungeon 5"},
        {Event::Event::RoomDungeon6, "Enter Dungeon 6"},
        {Event::Event::RoomDungeon7, "Enter Dungeon 7"},
        {Event::Event::RoomDungeon8, "Enter Dungeon 8"},
        {Event::Event::RoomDungeon9, "Enter Dungeon 9"},
        {Event::Event::RoomDungeon10, "Enter Dungeon 10"},
        {Event::Event::RoomDungeon11, "Enter Dungeon 11"},
        {Event::Event::RoomDungeon12, "Enter Dungeon 12"},
        {Event::Event::RoomDungeon13, "Enter Dungeon 13"},
        {Event::Event::RoomDungeon14, "Enter Dungeon 14"},
        {Event::Event::RoomDungeon15, "Enter Dungeon 15"},
        {Event::Event::RoomDungeon16, "Enter Dungeon 16"},
        {Event::Event::RoomDungeon17, "Enter Dungeon 17"},
        {Event::Event::RoomDungeon18, "Enter Dungeon 18"},
        {Event::Event::RoomDungeon19, "Enter Dungeon 19"},
        {Event::Event::RoomDungeon20, "Enter Dungeon 20"},
        {Event::Event::RoomDungeon21, "Enter Dungeon 21"},
        {Event::Event::RoomDungeon22, "Enter Dungeon 22"},
        {Event::Event::RoomDungeon23, "Enter Dungeon 23"},
        {Event::Event::RoomKeep0, "Enter Keep 0"},
        {Event::Event::RoomKeep1, "Enter Keep 1"},
        {Event::Event::RoomKeep2, "Enter Keep 2"},
        {Event::Event::RoomKeep3, "Enter Keep 3"},
        {Event::Event::RoomKeep4, "Enter Keep 4"},
        {Event::Event::RoomKeep5, "Enter Keep 5"},
        {Event::Event::RoomKeep6, "Enter Keep 6"},
        {Event::Event::RoomKeep7, "Enter Keep 7"},
        {Event::Event::RoomKeep8, "Enter Keep 8"},
        {Event::Event::RoomKeep9, "Enter Keep 9"},
        {Event::Event::RoomKeep10, "Enter Keep 10"},
        {Event::Event::RoomKeep11, "Enter Keep 11"},
        {Event::Event::RoomKeep12, "Enter Keep 12"},
        {Event::Event::RoomKeep13, "Enter Keep 13"},
        {Event::Event::RoomKeep14, "Enter Keep 14"},
        {Event::Event::RoomKeep15, "Enter Keep 15"},
        {Event::Event::RoomKeep16, "Enter Keep 16"},
        {Event::Event::RoomKeep17, "Enter Keep 17"},
        {Event::Event::RoomKeep18, "Enter Keep 18"},
        {Event::Event::RoomKeep19, "Enter Keep 19"},
        {Event::Event::RoomKeep20, "Enter Keep 20"},
        {Event::Event::RoomKeep21, "Enter Keep 21"},
        {Event::Event::RoomKeep22, "Enter Keep 22"},
        {Event::Event::RoomKeep23, "Enter Keep 23"},
        {Event::Event::RoomKeep24, "Enter Keep 24"},
        {Event::Event::RoomLibrary0, "Enter Library 0"},
        {Event::Event::RoomLibrary1, "Enter Library 1"},
        {Event::Event::RoomLibrary2, "Enter Library 2"},
        {Event::Event::RoomLibrary3, "Enter Library 3"},
        {Event::Event::RoomLibrary4, "Enter Library 4"},
        {Event::Event::RoomLibrary5, "Enter Library 5"},
        {Event::Event::RoomLibrary6, "Enter Library 6"},
        {Event::Event::RoomLibrary7, "Enter Library 7"},
        {Event::Event::RoomLibrary8, "Enter Library 8"},
        {Event::Event::RoomLibrary9, "Enter Library 9"},
        {Event::Event::RoomLibrary10, "Enter Library 10"},
        {Event::Event::RoomCastle0, "Enter Castle 0"},
        {Event::Event::RoomCastle1, "Enter Castle 1"},
        {Event::Event::RoomCastle2, "Enter Castle 2"},
        {Event::Event::RoomCastle3, "Enter Castle 3"},
        {Event::Event::RoomCastle4, "Enter Castle 4"},
        {Event::Event::RoomCastle5, "Enter Castle 5"},
        {Event::Event::RoomCastle6, "Enter Castle 6"},
        {Event::Event::RoomCastle7, "Enter Castle 7"},
        {Event::Event::RoomCastle8, "Enter Castle 8"},
        {Event::Event::RoomCastle9, "Enter Castle 9"},
        {Event::Event::RoomCastle10, "Enter Castle 10"},
        {Event::Event::RoomCastle11, "Enter Castle 11"},
        {Event::Event::RoomCastle12, "Enter Castle 12"},
        {Event::Event::RoomCastle13, "Enter Castle 13"},
        {Event::Event::RoomCastle14, "Enter Castle 14"},
        {Event::Event::RoomCastle15, "Enter Castle 15"},
        {Event::Event::RoomCastle16, "Enter Castle 16"},
        {Event::Event::RoomCastle17, "Enter Castle 17"},
        {Event::Event::RoomCastle18, "Enter Castle 18"},
        {Event::Event::RoomCastle19, "Enter Castle 19"},
        {Event::Event::RoomCastle20, "Enter Castle 20"},
        {Event::Event::RoomCastle21, "Enter Castle 21"},
        {Event::Event::RoomCastle22, "Enter Castle 22"},
        {Event::Event::RoomCastle23, "Enter Castle 23"},
        {Event::Event::RoomCastle24, "Enter Castle 24"},
        {Event::Event::RoomCastle25, "Enter Castle 25"},
        {Event::Event::RoomCastle26, "Enter Castle 26"},
        {Event::Event::RoomCastle27, "Enter Castle 27"},
        {Event::Event::RoomCastle28, "Enter Castle 28"},
        {Event::Event::RoomCastle29, "Enter Castle 29"},
        {Event::Event::RoomCastle30, "Enter Castle 30"},
        {Event::Event::RoomCastle31, "Enter Castle 31"},
        {Event::Event::RoomTheatre0, "Enter Theatre 0"},
        {Event::Event::RoomTheatre1, "Enter Theatre 1"},
        {Event::Event::RoomTheatre2, "Enter Theatre 2"},
        {Event::Event::RoomTheatre3, "Enter Theatre 3"},
        {Event::Event::RoomTheatre4, "Enter Theatre 4"},
        {Event::Event::RoomTheatre5, "Enter Theatre 5"},
        {Event::Event::RoomTheatre6, "Enter Theatre 6"},
        {Event::Event::RoomTheatre7, "Enter Theatre 7"},
        {Event::Event::RoomTheatre8, "Enter Theatre 8"},
        {Event::Event::RoomTheatre9, "Enter Theatre 9"},
        {Event::Event::RoomTheatre10, "Enter Theatre 10"},
        {Event::Event::RoomTheatre11, "Enter Theatre 11"},
        {Event::Event::RoomTheatre12, "Enter Theatre 12"},
        {Event::Event::RoomTheatre13, "Enter Theatre 13"},
        {Event::Event::RoomTheatre14, "Enter Theatre 14"},
        {Event::Event::RoomTheatre15, "Enter Theatre 15"},
        {Event::Event::RoomTheatre16, "Enter Theatre 16"},
        {Event::Event::RoomTheatre17, "Enter Theatre 17"},
        {Event::Event::RoomTheatre18, "Enter Theatre 18"},
        {Event::Event::RoomTheatre19, "Enter Theatre 19"},
        {Event::Event::RoomTheatre20, "Enter Theatre 20"},
        {Event::Event::RoomTheatre21, "Enter Theatre 21"},
        {Event::Event::RoomTheatre22, "Enter Theatre 22"},
        {Event::Event::RoomTheatre23, "Enter Theatre 23"},
        {Event::Event::RoomTheatre24, "Enter Theatre 24"},
        {Event::Event::RoomTower0, "Enter Tower 0"},
        {Event::Event::RoomTower1, "Enter Tower 1"},
        {Event::Event::RoomTower2, "Enter Tower 2"},
        {Event::Event::RoomTower4, "Enter Tower 4"},
        {Event::Event::RoomTower5, "Enter Tower 5"},
        {Event::Event::RoomTower6, "Enter Tower 6"},

        {Event::Event::FinishGame, "Finish Game"},
    };

    std::optional<Event::Event> start_event = Event::Event::RoomDungeon5;
    std::optional<Event::Event> end_event = Event::Event::RoomDungeon6;
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
