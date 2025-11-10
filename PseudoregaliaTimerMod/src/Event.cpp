#pragma once

#include "Event.hpp"

#include <chrono>
#include <map>
#include <optional>
#include <string>
#include <unordered_map>

#include "Unreal/FText.hpp"
#include "Unreal/UFunction.hpp"

#include "Logger.hpp"

namespace
{
    const std::map<Event::Event, std::string> event_to_string = {
        {Event::Event::StartGame, "Start Game"},
        {Event::Event::FinishGame, "Finish Game"},

        // Collectible
        {Event::Event::AbilityAscendantLight, "Collectible: Ability: Ascendant Light"},
        {Event::Event::AbilityClingGem, "Collectible: Ability: Cling Gem"},
        {Event::Event::AbilityDreamBreaker, "Collectible: Ability: Dream Breaker"},
        {Event::Event::AbilityIndignation, "Collectible: Ability: Indignation"},
        {Event::Event::AbilityMemento, "Collectible: Ability: Memento"},
        {Event::Event::AbilitySlide, "Collectible: Ability: Slide"},
        {Event::Event::AbilitySolarWind, "Collectible: Ability: Solar Wind"},
        {Event::Event::AbilitySoulCutter, "Collectible: Ability: Soul Cutter"},
        {Event::Event::AbilityStrikebreak, "Collectible: Ability: Strikebreak"},
        {Event::Event::AbilitySunGreaves, "Collectible: Ability: Sun Greaves"},
        {Event::Event::AbilitySunsetter, "Collectible: Ability: Sunsetter"},

        {Event::Event::AspectAerialFinesse, "Collectible: Aspect: Aerial Finesse"},
        {Event::Event::AspectClearMindCastle, "Collectible: Aspect: Clear Mind (Castle)"},
        {Event::Event::AspectClearMindKeep, "Collectible: Aspect: Clear Mind (Keep)"},
        {Event::Event::AspectClearMindLibrary, "Collectible: Aspect: Clear Mind (Library)"},
        {Event::Event::AspectEmpathyBailey, "Collectible: Aspect: Empathy (Bailey)"},
        {Event::Event::AspectEmpathyTheatre, "Collectible: Aspect: Empathy (Theatre)"},
        {Event::Event::AspectGoodGracesCastle, "Collectible: Aspect: Good Graces (Castle)"},
        {Event::Event::AspectGoodGracesDungeon, "Collectible: Aspect: Good Graces (Dungeon)"},
        {Event::Event::AspectHeliacalPower, "Collectible: Aspect: Heliacal Power"},
        {Event::Event::AspectMartialProwess, "Collectible: Aspect: Martial Prowess"},
        {Event::Event::AspectPilgrimage, "Collectible: Aspect: Pilgrimage"},

        {Event::Event::OutfitAGuardian, "Collectible: Outfit: A Guardian"},
        {Event::Event::OutfitBleedingHeart, "Collectible: Outfit: Bleeding Heart"},
        {Event::Event::OutfitChivalry, "Collectible: Outfit: Chivalry"},
        {Event::Event::OutfitClass, "Collectible: Outfit: Class"},
        {Event::Event::OutfitDevotion, "Collectible: Outfit: Devotion"},
        {Event::Event::OutfitNostalgia, "Collectible: Outfit: Nostalgia"},
        {Event::Event::OutfitProfessionalism, "Collectible: Outfit: Professionalism"},
        {Event::Event::OutfitSweater, "Collectible: Outfit: Sweater"},

        {Event::Event::HealthPieceBaileySteeple, "Collectible: Health Piece: Bailey Steeple HP"},
        {Event::Event::HealthPieceCastleBalcony, "Collectible: Health Piece: Castle Balcony HP"},
        {Event::Event::HealthPieceCastleCorner, "Collectible: Health Piece: Castle Corner HP"},
        {Event::Event::HealthPieceCastleCrawlers, "Collectible: Health Piece: Castle Crawlers HP"},
        {Event::Event::HealthPieceCastleRiver, "Collectible: Health Piece: Castle River HP"},
        {Event::Event::HealthPieceCastleScythes, "Collectible: Health Piece: Castle Scythes HP"},
        {Event::Event::HealthPieceDungeonAlcove, "Collectible: Health Piece: Dungeon Alcove HP"},
        {Event::Event::HealthPieceDungeonPoles, "Collectible: Health Piece: Dungeon Poles HP"},
        {Event::Event::HealthPieceKeepLocked, "Collectible: Health Piece: Keep Locked HP"},
        {Event::Event::HealthPieceLibraryBack, "Collectible: Health Piece: Library Back HP"},
        {Event::Event::HealthPieceLibraryLocked, "Collectible: Health Piece: Library Locked HP"},
        {Event::Event::HealthPieceTheatreAuditorium, "Collectible: Health Piece: Theatre Auditorium HP"},
        {Event::Event::HealthPieceTheatreBoxes, "Collectible: Health Piece: Theatre Boxes HP"},
        {Event::Event::HealthPieceUnderbellyBuilding, "Collectible: Health Piece: Underbelly Building HP"},
        {Event::Event::HealthPieceUnderbellyPillar, "Collectible: Health Piece: Underbelly Pillar HP"},
        {Event::Event::HealthPieceUnderbellyRafters, "Collectible: Health Piece: Underbelly Rafters HP"},

        {Event::Event::MajorKeyBailey, "Collectible: Major Key: Bailey Major Key"},
        {Event::Event::MajorKeyKeep, "Collectible: Major Key: Keep Major Key"},
        {Event::Event::MajorKeyTheatre, "Collectible: Major Key: Theatre Major Key"},
        {Event::Event::MajorKeyTower, "Collectible: Major Key: Tower Major Key"},
        {Event::Event::MajorKeyUnderbelly, "Collectible: Major Key: Underbelly Major Key"},

        {Event::Event::SmallKeyBaileyBuilding, "Collectible: Small Key: Bailey Building Small Key"},
        {Event::Event::SmallKeyCastleCrossroads, "Collectible: Small Key: Castle Crossroads Small Key"},
        {Event::Event::SmallKeyCastleTallRoom, "Collectible: Small Key: Castle Tall Room Small Key"},
        {Event::Event::SmallKeyDungeonStrongEyes, "Collectible: Small Key: Dungeon Strong Eyes Small Key"},
        {Event::Event::SmallKeyDungeonRafters, "Collectible: Small Key: Dungeon Rafters Small Key"},
        {Event::Event::SmallKeyKeepLeverRoom, "Collectible: Small Key: Keep Lever Room Small Key"},
        {Event::Event::SmallKeyUnderbellyBigRoom, "Collectible: Small Key: Underbelly Big Room Small Key"},

        // Transition
        {Event::Event::TransitionBaileyToCastle, "Transition: From Bailey: Bailey -> Castle"},
        {Event::Event::TransitionBaileyToTheatre, "Transition: From Bailey: Bailey -> Theatre"},
        {Event::Event::TransitionBaileyToTower, "Transition: From Bailey: Bailey -> Tower"},
        {Event::Event::TransitionBaileyToUnderbelly, "Transition: From Bailey: Bailey -> Underbelly"},

        {Event::Event::TransitionCastleToBailey, "Transition: From Castle: Castle -> Bailey"},
        {Event::Event::TransitionCastleToDungeon, "Transition: From Castle: Castle -> Dungeon"},
        {Event::Event::TransitionCastleToKeepLocked, "Transition: From Castle: Castle -> Keep (Locked)"},
        {Event::Event::TransitionCastleToKeepNorth, "Transition: From Castle: Castle -> Keep (North)"},
        {Event::Event::TransitionCastleToKeepSouth, "Transition: From Castle: Castle -> Keep (South)"},
        {Event::Event::TransitionCastleToLibrary, "Transition: From Castle: Castle -> Library"},
        {Event::Event::TransitionCastleToTheatreFront, "Transition: From Castle: Castle -> Theatre (Front)"},
        {Event::Event::TransitionCastleToTheatrePillar, "Transition: From Castle: Castle -> Theatre (Pillar)"},

        {Event::Event::TransitionChambersToTower, "Transition: From Chambers: Chambers -> Tower"},

        {Event::Event::TransitionDungeonToCastle, "Transition: From Dungeon: Dungeon -> Castle"},
        {Event::Event::TransitionDungeonToTheatre, "Transition: From Dungeon: Dungeon -> Theatre"},
        {Event::Event::TransitionDungeonToUnderbelly, "Transition: From Dungeon: Dungeon -> Underbelly"},

        {Event::Event::TransitionKeepToCastleLocked, "Transition: From Keep: Keep -> Castle (Locked)"},
        {Event::Event::TransitionKeepToCastleNorth, "Transition: From Keep: Keep -> Castle (North)"},
        {Event::Event::TransitionKeepToCastleSouth, "Transition: From Keep: Keep -> Castle (South)"},
        {Event::Event::TransitionKeepToTheatre, "Transition: From Keep: Keep -> Theatre"},
        {Event::Event::TransitionKeepToUnderbelly, "Transition: From Keep: Keep -> Underbelly"},

        {Event::Event::TransitionLibraryToCastle, "Transition: From Library: Library -> Castle"},

        {Event::Event::TransitionTheatreToBailey, "Transition: From Theatre: Theatre -> Bailey"},
        {Event::Event::TransitionTheatreToCastleNorthwest, "Transition: From Theatre: Theatre -> Castle (Northwest)"},
        {Event::Event::TransitionTheatreToCastleWest, "Transition: From Theatre: Theatre -> Castle (West)"},
        {Event::Event::TransitionTheatreToDungeon, "Transition: From Theatre: Theatre -> Dungeon"},
        {Event::Event::TransitionTheatreToKeep, "Transition: From Theatre: Theatre -> Keep"},

        {Event::Event::TransitionTowerToBailey, "Transition: From Tower: Tower -> Bailey"},
        {Event::Event::TransitionTowerToChambers, "Transition: From Tower: Tower -> Chambers"},

        {Event::Event::TransitionUnderbellyToBailey, "Transition: From Underbelly: Underbelly -> Bailey"},
        {Event::Event::TransitionUnderbellyToDungeon, "Transition: From Underbelly: Underbelly -> Dungeon"},
        {Event::Event::TransitionUnderbellyToKeep, "Transition: From Underbelly: Underbelly -> Keep"},

        // Enter Room
        {Event::Event::RoomBailey0, "Enter Room: Bailey: Enter Bailey 0"},
        {Event::Event::RoomBailey1, "Enter Room: Bailey: Enter Bailey 1"},
        {Event::Event::RoomBailey2, "Enter Room: Bailey: Enter Bailey 2"},
        {Event::Event::RoomBailey3, "Enter Room: Bailey: Enter Bailey 3"},

        {Event::Event::RoomCastle0, "Enter Room: Castle: Enter Castle 0"},
        {Event::Event::RoomCastle1, "Enter Room: Castle: Enter Castle 1"},
        {Event::Event::RoomCastle2, "Enter Room: Castle: Enter Castle 2"},
        {Event::Event::RoomCastle3, "Enter Room: Castle: Enter Castle 3"},
        {Event::Event::RoomCastle4, "Enter Room: Castle: Enter Castle 4"},
        {Event::Event::RoomCastle5, "Enter Room: Castle: Enter Castle 5"},
        {Event::Event::RoomCastle6, "Enter Room: Castle: Enter Castle 6"},
        {Event::Event::RoomCastle7, "Enter Room: Castle: Enter Castle 7"},
        {Event::Event::RoomCastle8, "Enter Room: Castle: Enter Castle 8"},
        {Event::Event::RoomCastle9, "Enter Room: Castle: Enter Castle 9"},
        {Event::Event::RoomCastle10, "Enter Room: Castle: Enter Castle 10"},
        {Event::Event::RoomCastle11, "Enter Room: Castle: Enter Castle 11"},
        {Event::Event::RoomCastle12, "Enter Room: Castle: Enter Castle 12"},
        {Event::Event::RoomCastle13, "Enter Room: Castle: Enter Castle 13"},
        {Event::Event::RoomCastle14, "Enter Room: Castle: Enter Castle 14"},
        {Event::Event::RoomCastle15, "Enter Room: Castle: Enter Castle 15"},
        {Event::Event::RoomCastle16, "Enter Room: Castle: Enter Castle 16"},
        {Event::Event::RoomCastle17, "Enter Room: Castle: Enter Castle 17"},
        {Event::Event::RoomCastle18, "Enter Room: Castle: Enter Castle 18"},
        {Event::Event::RoomCastle19, "Enter Room: Castle: Enter Castle 19"},
        {Event::Event::RoomCastle20, "Enter Room: Castle: Enter Castle 20"},
        {Event::Event::RoomCastle21, "Enter Room: Castle: Enter Castle 21"},
        {Event::Event::RoomCastle22, "Enter Room: Castle: Enter Castle 22"},
        {Event::Event::RoomCastle23, "Enter Room: Castle: Enter Castle 23"},
        {Event::Event::RoomCastle24, "Enter Room: Castle: Enter Castle 24"},
        {Event::Event::RoomCastle25, "Enter Room: Castle: Enter Castle 25"},
        {Event::Event::RoomCastle26, "Enter Room: Castle: Enter Castle 26"},
        {Event::Event::RoomCastle27, "Enter Room: Castle: Enter Castle 27"},
        {Event::Event::RoomCastle28, "Enter Room: Castle: Enter Castle 28"},
        {Event::Event::RoomCastle29, "Enter Room: Castle: Enter Castle 29"},
        {Event::Event::RoomCastle30, "Enter Room: Castle: Enter Castle 30"},
        {Event::Event::RoomCastle31, "Enter Room: Castle: Enter Castle 31"},

        {Event::Event::RoomDungeon0, "Enter Room: Dungeon: Enter Dungeon 0"},
        {Event::Event::RoomDungeon1, "Enter Room: Dungeon: Enter Dungeon 1"},
        {Event::Event::RoomDungeon2, "Enter Room: Dungeon: Enter Dungeon 2"},
        {Event::Event::RoomDungeon3, "Enter Room: Dungeon: Enter Dungeon 3"},
        {Event::Event::RoomDungeon4, "Enter Room: Dungeon: Enter Dungeon 4"},
        {Event::Event::RoomDungeon5, "Enter Room: Dungeon: Enter Dungeon 5"},
        {Event::Event::RoomDungeon6, "Enter Room: Dungeon: Enter Dungeon 6"},
        {Event::Event::RoomDungeon7, "Enter Room: Dungeon: Enter Dungeon 7"},
        {Event::Event::RoomDungeon8, "Enter Room: Dungeon: Enter Dungeon 8"},
        {Event::Event::RoomDungeon9, "Enter Room: Dungeon: Enter Dungeon 9"},
        {Event::Event::RoomDungeon10, "Enter Room: Dungeon: Enter Dungeon 10"},
        {Event::Event::RoomDungeon11, "Enter Room: Dungeon: Enter Dungeon 11"},
        {Event::Event::RoomDungeon12, "Enter Room: Dungeon: Enter Dungeon 12"},
        {Event::Event::RoomDungeon13, "Enter Room: Dungeon: Enter Dungeon 13"},
        {Event::Event::RoomDungeon14, "Enter Room: Dungeon: Enter Dungeon 14"},
        {Event::Event::RoomDungeon15, "Enter Room: Dungeon: Enter Dungeon 15"},
        {Event::Event::RoomDungeon16, "Enter Room: Dungeon: Enter Dungeon 16"},
        {Event::Event::RoomDungeon17, "Enter Room: Dungeon: Enter Dungeon 17"},
        {Event::Event::RoomDungeon18, "Enter Room: Dungeon: Enter Dungeon 18"},
        {Event::Event::RoomDungeon19, "Enter Room: Dungeon: Enter Dungeon 19"},
        {Event::Event::RoomDungeon20, "Enter Room: Dungeon: Enter Dungeon 20"},
        {Event::Event::RoomDungeon21, "Enter Room: Dungeon: Enter Dungeon 21"},
        {Event::Event::RoomDungeon22, "Enter Room: Dungeon: Enter Dungeon 22"},
        {Event::Event::RoomDungeon23, "Enter Room: Dungeon: Enter Dungeon 23"},

        {Event::Event::RoomKeep0, "Enter Room: Keep: Enter Keep 0"},
        {Event::Event::RoomKeep1, "Enter Room: Keep: Enter Keep 1"},
        {Event::Event::RoomKeep2, "Enter Room: Keep: Enter Keep 2"},
        {Event::Event::RoomKeep3, "Enter Room: Keep: Enter Keep 3"},
        {Event::Event::RoomKeep4, "Enter Room: Keep: Enter Keep 4"},
        {Event::Event::RoomKeep5, "Enter Room: Keep: Enter Keep 5"},
        {Event::Event::RoomKeep6, "Enter Room: Keep: Enter Keep 6"},
        {Event::Event::RoomKeep7, "Enter Room: Keep: Enter Keep 7"},
        {Event::Event::RoomKeep8, "Enter Room: Keep: Enter Keep 8"},
        {Event::Event::RoomKeep9, "Enter Room: Keep: Enter Keep 9"},
        {Event::Event::RoomKeep10, "Enter Room: Keep: Enter Keep 10"},
        {Event::Event::RoomKeep11, "Enter Room: Keep: Enter Keep 11"},
        {Event::Event::RoomKeep12, "Enter Room: Keep: Enter Keep 12"},
        {Event::Event::RoomKeep13, "Enter Room: Keep: Enter Keep 13"},
        {Event::Event::RoomKeep14, "Enter Room: Keep: Enter Keep 14"},
        {Event::Event::RoomKeep15, "Enter Room: Keep: Enter Keep 15"},
        {Event::Event::RoomKeep16, "Enter Room: Keep: Enter Keep 16"},
        {Event::Event::RoomKeep17, "Enter Room: Keep: Enter Keep 17"},
        {Event::Event::RoomKeep18, "Enter Room: Keep: Enter Keep 18"},
        {Event::Event::RoomKeep19, "Enter Room: Keep: Enter Keep 19"},
        {Event::Event::RoomKeep20, "Enter Room: Keep: Enter Keep 20"},
        {Event::Event::RoomKeep21, "Enter Room: Keep: Enter Keep 21"},
        {Event::Event::RoomKeep22, "Enter Room: Keep: Enter Keep 22"},
        {Event::Event::RoomKeep23, "Enter Room: Keep: Enter Keep 23"},
        {Event::Event::RoomKeep24, "Enter Room: Keep: Enter Keep 24"},

        {Event::Event::RoomLibrary0, "Enter Room: Library: Enter Library 0"},
        {Event::Event::RoomLibrary1, "Enter Room: Library: Enter Library 1"},
        {Event::Event::RoomLibrary2, "Enter Room: Library: Enter Library 2"},
        {Event::Event::RoomLibrary3, "Enter Room: Library: Enter Library 3"},
        {Event::Event::RoomLibrary4, "Enter Room: Library: Enter Library 4"},
        {Event::Event::RoomLibrary5, "Enter Room: Library: Enter Library 5"},
        {Event::Event::RoomLibrary6, "Enter Room: Library: Enter Library 6"},
        {Event::Event::RoomLibrary7, "Enter Room: Library: Enter Library 7"},
        {Event::Event::RoomLibrary8, "Enter Room: Library: Enter Library 8"},
        {Event::Event::RoomLibrary9, "Enter Room: Library: Enter Library 9"},
        {Event::Event::RoomLibrary10, "Enter Room: Library: Enter Library 10"},

        {Event::Event::RoomTheatre0, "Enter Room: Theatre: Enter Theatre 0"},
        {Event::Event::RoomTheatre1, "Enter Room: Theatre: Enter Theatre 1"},
        {Event::Event::RoomTheatre2, "Enter Room: Theatre: Enter Theatre 2"},
        {Event::Event::RoomTheatre3, "Enter Room: Theatre: Enter Theatre 3"},
        {Event::Event::RoomTheatre4, "Enter Room: Theatre: Enter Theatre 4"},
        {Event::Event::RoomTheatre5, "Enter Room: Theatre: Enter Theatre 5"},
        {Event::Event::RoomTheatre6, "Enter Room: Theatre: Enter Theatre 6"},
        {Event::Event::RoomTheatre7, "Enter Room: Theatre: Enter Theatre 7"},
        {Event::Event::RoomTheatre8, "Enter Room: Theatre: Enter Theatre 8"},
        {Event::Event::RoomTheatre9, "Enter Room: Theatre: Enter Theatre 9"},
        {Event::Event::RoomTheatre10, "Enter Room: Theatre: Enter Theatre 10"},
        {Event::Event::RoomTheatre11, "Enter Room: Theatre: Enter Theatre 11"},
        {Event::Event::RoomTheatre12, "Enter Room: Theatre: Enter Theatre 12"},
        {Event::Event::RoomTheatre13, "Enter Room: Theatre: Enter Theatre 13"},
        {Event::Event::RoomTheatre14, "Enter Room: Theatre: Enter Theatre 14"},
        {Event::Event::RoomTheatre15, "Enter Room: Theatre: Enter Theatre 15"},
        {Event::Event::RoomTheatre16, "Enter Room: Theatre: Enter Theatre 16"},
        {Event::Event::RoomTheatre17, "Enter Room: Theatre: Enter Theatre 17"},
        {Event::Event::RoomTheatre18, "Enter Room: Theatre: Enter Theatre 18"},
        {Event::Event::RoomTheatre19, "Enter Room: Theatre: Enter Theatre 19"},
        {Event::Event::RoomTheatre20, "Enter Room: Theatre: Enter Theatre 20"},
        {Event::Event::RoomTheatre21, "Enter Room: Theatre: Enter Theatre 21"},
        {Event::Event::RoomTheatre22, "Enter Room: Theatre: Enter Theatre 22"},
        {Event::Event::RoomTheatre23, "Enter Room: Theatre: Enter Theatre 23"},
        {Event::Event::RoomTheatre24, "Enter Room: Theatre: Enter Theatre 24"},

        {Event::Event::RoomTower0, "Enter Room: Tower: Enter Tower 0"},
        {Event::Event::RoomTower1, "Enter Room: Tower: Enter Tower 1"},
        {Event::Event::RoomTower2, "Enter Room: Tower: Enter Tower 2"},
        {Event::Event::RoomTower4, "Enter Room: Tower: Enter Tower 4"},
        {Event::Event::RoomTower5, "Enter Room: Tower: Enter Tower 5"},
        {Event::Event::RoomTower6, "Enter Room: Tower: Enter Tower 6"},

        {Event::Event::RoomUnderbelly0, "Enter Room: Underbelly: Enter Underbelly 0"},
        {Event::Event::RoomUnderbelly1, "Enter Room: Underbelly: Enter Underbelly 1"},
        {Event::Event::RoomUnderbelly2, "Enter Room: Underbelly: Enter Underbelly 2"},
        {Event::Event::RoomUnderbelly3, "Enter Room: Underbelly: Enter Underbelly 3"},
        {Event::Event::RoomUnderbelly4, "Enter Room: Underbelly: Enter Underbelly 4"},
        {Event::Event::RoomUnderbelly5, "Enter Room: Underbelly: Enter Underbelly 5"},
        {Event::Event::RoomUnderbelly6, "Enter Room: Underbelly: Enter Underbelly 6"},
        {Event::Event::RoomUnderbelly7, "Enter Room: Underbelly: Enter Underbelly 7"},
        {Event::Event::RoomUnderbelly8, "Enter Room: Underbelly: Enter Underbelly 8"},
        {Event::Event::RoomUnderbelly9, "Enter Room: Underbelly: Enter Underbelly 9"},
        {Event::Event::RoomUnderbelly10, "Enter Room: Underbelly: Enter Underbelly 10"},
        {Event::Event::RoomUnderbelly11, "Enter Room: Underbelly: Enter Underbelly 11"},
        {Event::Event::RoomUnderbelly12, "Enter Room: Underbelly: Enter Underbelly 12"},
        {Event::Event::RoomUnderbelly13, "Enter Room: Underbelly: Enter Underbelly 13"},
        {Event::Event::RoomUnderbelly14, "Enter Room: Underbelly: Enter Underbelly 14"},
        {Event::Event::RoomUnderbelly15, "Enter Room: Underbelly: Enter Underbelly 15"},
        {Event::Event::RoomUnderbelly16, "Enter Room: Underbelly: Enter Underbelly 16"},
        {Event::Event::RoomUnderbelly17, "Enter Room: Underbelly: Enter Underbelly 17"},
        {Event::Event::RoomUnderbelly18, "Enter Room: Underbelly: Enter Underbelly 18"},
        {Event::Event::RoomUnderbelly19, "Enter Room: Underbelly: Enter Underbelly 19"},
        {Event::Event::RoomUnderbelly20, "Enter Room: Underbelly: Enter Underbelly 20"},
        {Event::Event::RoomUnderbelly21, "Enter Room: Underbelly: Enter Underbelly 21"},
        {Event::Event::RoomUnderbelly22, "Enter Room: Underbelly: Enter Underbelly 22"},
        {Event::Event::RoomUnderbelly23, "Enter Room: Underbelly: Enter Underbelly 23"},
        {Event::Event::RoomUnderbelly24, "Enter Room: Underbelly: Enter Underbelly 24"},
        {Event::Event::RoomUnderbelly25, "Enter Room: Underbelly: Enter Underbelly 25"},
        {Event::Event::RoomUnderbelly26, "Enter Room: Underbelly: Enter Underbelly 26"},
        {Event::Event::RoomUnderbelly27, "Enter Room: Underbelly: Enter Underbelly 27"},
        {Event::Event::RoomUnderbelly28, "Enter Room: Underbelly: Enter Underbelly 28"},
        {Event::Event::RoomUnderbelly29, "Enter Room: Underbelly: Enter Underbelly 29"},
        {Event::Event::RoomUnderbelly30, "Enter Room: Underbelly: Enter Underbelly 30"},
        {Event::Event::RoomUnderbelly31, "Enter Room: Underbelly: Enter Underbelly 31"},
        {Event::Event::RoomUnderbelly32, "Enter Room: Underbelly: Enter Underbelly 32"},
        {Event::Event::RoomUnderbelly33, "Enter Room: Underbelly: Enter Underbelly 33"},
        {Event::Event::RoomUnderbelly34, "Enter Room: Underbelly: Enter Underbelly 34"},
        {Event::Event::RoomUnderbelly35, "Enter Room: Underbelly: Enter Underbelly 35"},
        {Event::Event::RoomUnderbelly36, "Enter Room: Underbelly: Enter Underbelly 36"},
    };

    // event_to_string contains the full event names, including categories. we create this map to pre-parse the actual
    // event names for logging.
    const std::map<Event::Event, std::string> event_to_string_short = ([]() -> std::map<Event::Event, std::string> {
        std::map<Event::Event, std::string> m;
        for (const auto& [event, event_string] : event_to_string)
        {
            auto pos = event_string.rfind(": ");
            if (pos == std::string::npos)
            {
                m[event] = event_string;
            }
            else
            {
                // add 2 to account for delimiter size
                m[event] = event_string.substr(pos + 2);
            }
        }
        return m;
    })();

    // the event map is ordered which means each event has an index, so we create this vector to be able to map an index
    // back to an event
    const std::vector<Event::Event> event_list = ([]() -> std::vector<Event::Event> {
        std::vector<Event::Event> m;
        m.reserve(event_to_string.size());
        for (const auto& [event, _] : event_to_string)
        {
            m.push_back(event);
        }
        return m;
    })();

    bool initial_event_load_finished = false;
    std::optional<Event::Event> start_event = {};
    std::optional<Event::Event> end_event = {};
    std::optional<std::chrono::steady_clock::time_point> start_time = {};
    std::optional<int64_t> elapsed_millis = {};
    std::optional<int64_t> target_millis = {};
    bool timer_running = false;
    bool reset_timer_queued = false;

    std::unordered_map<Event::Event, std::unordered_map<Event::Event, int64_t>> pbs = {};

    std::string MillisToString(int64_t);

    void SetEvents(int32_t, int32_t);

    int64_t SetTimeToCurrent(RC::Unreal::UObject*);
    void SetTimeToElapsed(RC::Unreal::UObject*);
    void SetTarget(RC::Unreal::UObject*);
    void SetDiffByElapsed(RC::Unreal::UObject*);
    void TrySetDiffPos(RC::Unreal::UObject*, int64_t);
    void ClearTime(RC::Unreal::UObject*);
    void ClearTarget(RC::Unreal::UObject*);
    void ClearDiff(RC::Unreal::UObject*);

    std::optional<int64_t> GetPB();
    void SetPBFromElapsed();
}

void Event::Triggered(Event event)
{
    if (!event_to_string.contains(event))
    {
        Log("unknown event triggered", LogType::Warning);
        return;
    }

    std::string timer_str;
    if (!start_time && start_event && *start_event == event && end_event)
    {
        // start timer event
        start_time = std::chrono::steady_clock::now();
        elapsed_millis.reset();
        timer_str = " (0.000)";

        auto pb = GetPB();
        if (pb)
        {
            target_millis = *pb;
        }
    }
    else if (start_time && end_event && *end_event == event)
    {
        // end timer event
        elapsed_millis = (std::chrono::steady_clock::now() - *start_time).count() / 1000000LL;
        start_time.reset();
        timer_str = " (" + MillisToString(*elapsed_millis) + ")";

        auto pb = GetPB();
        if (!pb || *elapsed_millis < *pb)
        {
            SetPBFromElapsed();
        }
    }
    else if (start_time)
    {
        // mid timer event
        auto current_millis = (std::chrono::steady_clock::now() - *start_time).count() / 1000000LL;
        timer_str = " (" + MillisToString(current_millis) + ")";
    }
    Log("e: " + event_to_string_short.at(event) + timer_str);
}

void Event::InitializeTimer(RC::Unreal::UObject* manager_obj)
{
    if (!initial_event_load_finished)
    {
        auto start_index = *manager_obj->GetValuePtrByPropertyName<int32_t>(L"StartIndex");
        auto end_index = *manager_obj->GetValuePtrByPropertyName<int32_t>(L"EndIndex");
        SetEvents(start_index, end_index);
        initial_event_load_finished = true;
    }
    if (reset_timer_queued)
    {
        // if a reset was queued but never executed in the previous scene, we want to ignore it. this function being run
        // means that the timer is uninitialized anyway.
        reset_timer_queued = false;
    }
    if (!*manager_obj->GetValuePtrByPropertyName<bool>(L"Run")) return;
    auto widget = *manager_obj->GetValuePtrByPropertyName<RC::Unreal::UObject*>(L"TimerWidgetRef");
    if (start_time)
    {
        SetTimeToCurrent(widget);
    }
    else if (elapsed_millis)
    {
        SetTimeToElapsed(widget);
    }
    if (target_millis)
    {
        SetTarget(widget);
        if (elapsed_millis)
        {
            SetDiffByElapsed(widget);
        }
    }
}

void Event::InitializeOptionsWidget(RC::Unreal::UObject* widget)
{
    auto events = widget->GetValuePtrByPropertyName<RC::Unreal::TArray<RC::Unreal::FText>>(L"Events");
    if (events->Num() > 0) return;

    events->Reserve(event_to_string.size());
    for (const auto& [_, event_string] : event_to_string)
    {
        events->Add(RC::Unreal::FText(Logger::ToWide(event_string)));
    }
}

void Event::UpdateEvents(RC::Unreal::UObject* widget)
{
    auto start_index = *widget->GetValuePtrByPropertyName<int32_t>(L"StartIndex");
    auto end_index = *widget->GetValuePtrByPropertyName<int32_t>(L"EndIndex");
    SetEvents(start_index, end_index);
}

void Event::UpdateTimer(RC::Unreal::UObject* manager_obj)
{
    auto widget = *manager_obj->GetValuePtrByPropertyName<RC::Unreal::UObject*>(L"TimerWidgetRef");
    if (reset_timer_queued)
    {
        ClearTime(widget);
        ClearTarget(widget);
        ClearDiff(widget);
        reset_timer_queued = false;
    }
    else if (timer_running && elapsed_millis)
    {
        // segment has finished
        timer_running = false;

        SetTimeToElapsed(widget);
        if (target_millis)
        {
            SetDiffByElapsed(widget);
        }
    }
    else if (!timer_running && start_time)
    {
        // timer not initialized
        timer_running = true;

        SetTimeToCurrent(widget);
        SetTarget(widget);
        ClearDiff(widget);
    }
    else if (start_time)
    {
        // timer running and already initialized
        auto current_millis = SetTimeToCurrent(widget);
        if (target_millis)
        {
            TrySetDiffPos(widget, current_millis);
        }
    }
}

bool Event::Reset()
{
    if (start_time || elapsed_millis)
    {
        Log("resetting timer");

        start_time.reset();
        elapsed_millis.reset();
        target_millis.reset();
        timer_running = false;
        return true;
    }
    return false;
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

void SetEvents(int32_t start_index, int32_t end_index)
{
    if (start_index >= 0 && size_t(start_index) < event_list.size())
    {
        start_event = event_list[start_index];
        Log("start event set to " + event_to_string_short.at(*start_event));
    }
    else
    {
        Log("start event index " + std::to_string(start_index) + " does not correspond to an event");
    }
    if (end_index >= 0 && size_t(end_index) < event_list.size())
    {
        end_event = event_list[end_index];
        Log("end event set to " + event_to_string_short.at(*end_event));
    }
    else
    {
        Log("end event index " + std::to_string(end_index) + " does not correspond to an event");
    }

    if (Event::Reset())
    {
        reset_timer_queued = true;
    }
}

// expects start_time to contain a value; returns current millis
int64_t SetTimeToCurrent(RC::Unreal::UObject* widget)
{
    auto current_millis = (std::chrono::steady_clock::now() - *start_time).count() / 1000000LL;
    auto current_str = Logger::ToWide(MillisToString(current_millis));
    auto time = widget->GetValuePtrByPropertyName<RC::Unreal::FText>(L"Time");
    time->SetString(RC::Unreal::FString(current_str.c_str()));
    return current_millis;
}

// expects elapsed_millis to contain a value
void SetTimeToElapsed(RC::Unreal::UObject* widget)
{
    auto elapsed_str = Logger::ToWide(MillisToString(*elapsed_millis));
    auto time = widget->GetValuePtrByPropertyName<RC::Unreal::FText>(L"Time");
    time->SetString(RC::Unreal::FString(elapsed_str.c_str()));
}

void SetTarget(RC::Unreal::UObject* widget)
{
    auto target = widget->GetValuePtrByPropertyName<RC::Unreal::FText>(L"Target");
    if (target_millis)
    {
        auto target_str = Logger::ToWide(MillisToString(*target_millis));
        target->SetString(RC::Unreal::FString(target_str.c_str()));
    }
    else
    {
        target->SetString(RC::Unreal::FString());
    }
}

// expects target_millis and elapsed_millis to contain a value
void SetDiffByElapsed(RC::Unreal::UObject* widget)
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

// expects target_millis to contain a value
void TrySetDiffPos(RC::Unreal::UObject* widget, int64_t current_millis)
{
    if (current_millis > *target_millis)
    {
        auto diff_millis = current_millis - *target_millis;
        auto diff_str = L"+" + Logger::ToWide(MillisToString(diff_millis));
        auto diff_pos = widget->GetValuePtrByPropertyName<RC::Unreal::FText>(L"DiffPos");
        diff_pos->SetString(RC::Unreal::FString(diff_str.c_str()));
    }
}

void ClearTime(RC::Unreal::UObject* widget)
{
    auto time = widget->GetValuePtrByPropertyName<RC::Unreal::FText>(L"Time");
    time->SetString(RC::Unreal::FString());
}

void ClearTarget(RC::Unreal::UObject* widget)
{
    auto target = widget->GetValuePtrByPropertyName<RC::Unreal::FText>(L"Target");
    target->SetString(RC::Unreal::FString());

}

void ClearDiff(RC::Unreal::UObject* widget)
{
    auto diff_pos = widget->GetValuePtrByPropertyName<RC::Unreal::FText>(L"DiffPos");
    diff_pos->SetString(RC::Unreal::FString());
    auto diff_neg = widget->GetValuePtrByPropertyName<RC::Unreal::FText>(L"DiffNeg");
    diff_neg->SetString(RC::Unreal::FString());
}

// expects start_event and end_event to contain a value
std::optional<int64_t> GetPB()
{
    if (!pbs.contains(*start_event)) return {};
    const auto& from_start = pbs.at(*start_event);
    if (!from_start.contains(*end_event)) return {};
    return from_start.at(*end_event);
}

// expects start_event, end_event, and elapsed_millis to all contain values
void SetPBFromElapsed()
{
    pbs[*start_event][*end_event] = *elapsed_millis;
}

} // namespace
