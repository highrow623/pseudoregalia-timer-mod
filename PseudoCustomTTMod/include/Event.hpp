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

        SmallKeyDungeonRafters,
        SmallKeyDungeonStrongEyes,
        SmallKeyCastleCrossroads,
        SmallKeyCastleTallRoom,
        SmallKeyUnderbellyBigRoom,
        SmallKeyKeepLeverRoom,
        SmallKeyBaileyBuilding,

        HealthPieceLibraryBack,
        HealthPieceLibraryLocked,
        HealthPieceCastleCorner,
        HealthPieceCastleBalcony,
        HealthPieceCastleCrawlers,
        HealthPieceCastleScythes,
        HealthPieceCastleRiver,
        HealthPieceBaileySteeple,
        HealthPieceKeepLocked,
        HealthPieceUnderbellyRafters,
        HealthPieceUnderbellyPillar,
        HealthPieceUnderbellyBuilding,
        HealthPieceTheatreAuditorium,
        HealthPieceTheatreBoxes,
        HealthPieceDungeonAlcove,
        HealthPieceDungeonPoles,

        AbilityDreamBreaker,
        AbilityIndignation,
        AbilitySlide,
        AbilitySolarWind,
        AbilitySunGreaves,
        AbilitySunsetter,
        AbilityClingGem,
        AbilityAscendantLight,
        AbilityStrikebreak,
        AbilitySoulCutter,

        AspectClearMindLibrary,
        AspectClearMindKeep,
        AspectClearMindCastle,
        AspectEmpathyBailey,
        AspectEmpathyTheatre,
        AspectGoodGracesCastle,
        AspectGoodGracesDungeon,
        AspectMartialProwess,
        AspectPilgrimage,
        AspectAerialFinesse,
        AspectHeliacalPower,

        Memento,

        AttireProfessionalism,
        AttireAGuardian,
        AttireChivalry,
        AttireBleedingHeart,
        AttireNostalgia,
        AttireDevotion,
        AttireClass,
        AttireSweater,

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
