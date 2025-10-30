#pragma once

namespace Event
{
    enum class Event
    {
        StartGame, // TODO support trigger

        MajorKeyBailey,
        MajorKeyUnderbelly,
        MajorKeyTower,
        MajorKeyKeep,
        MajorKeyTheatre,

        SmallKeyDungeonRafters, // TODO support trigger
        SmallKeyDungeonStrongEyes, // TODO support trigger
        SmallKeyCastleCrossroads, // TODO support trigger
        SmallKeyCastleTallRoom, // TODO support trigger
        SmallKeyUnderbellyBigRoom, // TODO support trigger
        SmallKeyKeepLeverRoom, // TODO support trigger
        SmallKeyBaileyBuilding, // TODO support trigger

        HealthPieceLibraryBack, // TODO support trigger
        HealthPieceLibraryLocked, // TODO support trigger
        HealthPieceCastleCorner, // TODO support trigger
        HealthPieceCastleBalcony, // TODO support trigger
        HealthPieceCastleCrawlers, // TODO support trigger
        HealthPieceCastleScythes, // TODO support trigger
        HealthPieceCastleRiver, // TODO support trigger
        HealthPieceBaileySteeple, // TODO support trigger
        HealthPieceKeepLocked, // TODO support trigger
        HealthPieceUnderbellyRafters, // TODO support trigger
        HealthPieceUnderbellyPillar, // TODO support trigger
        HealthPieceUnderbellyBuilding, // TODO support trigger
        HealthPieceTheatreAuditorium, // TODO support trigger
        HealthPieceTheatreBoxes, // TODO support trigger
        HealthPieceDungeonAlcove, // TODO support trigger
        HealthPieceDungeonPoles, // TODO support trigger

        AbilityDreamBreaker, // TODO support trigger
        AbilityIndignation, // TODO support trigger
        AbilitySlide, // TODO support trigger
        AbilitySolarWind, // TODO support trigger
        AbilitySunGreaves, // TODO support trigger
        AbilitySunsetter, // TODO support trigger
        AbilityClingGem, // TODO support trigger
        AbilityAscendantLight, // TODO support trigger
        AbilityStrikebreak, // TODO support trigger
        AbilitySoulCutter, // TODO support trigger

        AspectClearMindLibrary, // TODO support trigger
        AspectClearMindKeep, // TODO support trigger
        AspectClearMindCastle, // TODO support trigger
        AspectEmpathyBailey, // TODO support trigger
        AspectEmpathyTheatre, // TODO support trigger
        AspectGoodGracesCastle, // TODO support trigger
        AspectGoodGracesDungeon, // TODO support trigger
        AspectMartialProwess, // TODO support trigger
        AspectPilgrimage, // TODO support trigger
        AspectAerialFinesse, // TODO support trigger
        AspectHeliacalPower, // TODO support trigger

        Memento, // TODO support trigger

        AttireProfessionalism, // TODO support trigger
        AttireAGuardian, // TODO support trigger
        AttireChivalry, // TODO support trigger
        AttireBleedingHeart, // TODO support trigger
        AttireNostalgia, // TODO support trigger
        AttireDevotion, // TODO support trigger
        AttireClass, // TODO support trigger
        AttireSweater, // TODO support trigger

        TransitionDungeonToCastle, // TODO support trigger
        TransitionDungeonToUnderbelly, // TODO support trigger
        TransitionDungeonToTheatre, // TODO support trigger
        TransitionCastleToDungeon, // TODO support trigger
        TransitionCastleToBailey, // TODO support trigger
        TransitionCastleToKeepSouth, // TODO support trigger
        TransitionCastleToKeepLocked, // TODO support trigger
        TransitionCastleToKeepNorth, // TODO support trigger
        TransitionCastleToLibrary, // TODO support trigger
        TransitionCastleToTheatrePillar, // TODO support trigger
        TransitionCastleToTheatreFront, // TODO support trigger
        TransitionLibraryToCastle, // TODO support trigger
        TransitionBaileyToCastle, // TODO support trigger
        TransitionBaileyToUnderbelly, // TODO support trigger
        TransitionBaileyToTower, // TODO support trigger
        TransitionBaileyToTheatre, // TODO support trigger
        TransitionKeepToCastleSouth, // TODO support trigger
        TransitionKeepToCastleLocked, // TODO support trigger
        TransitionKeepToCastleNorth, // TODO support trigger
        TransitionKeepToUnderbelly, // TODO support trigger
        TransitionKeepToTheatre, // TODO support trigger
        TransitionUnderbellyToDungeon, // TODO support trigger
        TransitionUnderbellyToBailey, // TODO support trigger
        TransitionUnderbellyToKeep, // TODO support trigger
        TransitionTheatreToDungeon, // TODO support trigger
        TransitionTheatreToCastleWest, // TODO support trigger
        TransitionTheatreToCastleNorthwest, // TODO support trigger
        TransitionTheatreToBailey, // TODO support trigger
        TransitionTheatreToKeep, // TODO support trigger
        TransitionTowerToBailey, // TODO support trigger
        TransitionTowerToChambers, // TODO support trigger
        TransitionChambersToTower, // TODO support trigger

        FinishGame, // TODO support trigger
    };

    void Triggered(Event);
}
