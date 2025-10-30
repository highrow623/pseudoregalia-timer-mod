#pragma once

#include "Event.hpp"

#include <string>
#include <map>

#include "Logger.hpp"

namespace
{
    std::map<Event::Event, std::string> event_to_string = {
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
}

void Event::Triggered(Event event)
{
    if (!event_to_string.contains(event))
    {
        Log("unknown event triggered", LogType::Warning);
        return;
    }
    Log("e: " + event_to_string.at(event));
}
