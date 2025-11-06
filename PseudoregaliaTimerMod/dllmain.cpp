#include <Mod/CppUserModBase.hpp>

#include "Unreal/Hooks.hpp"

#include "Logger.hpp"
#include "ModHooks.hpp"

class PseudoregaliaTimerMod : public RC::CppUserModBase
{
public:
    PseudoregaliaTimerMod() : CppUserModBase()
    {
        ModName = STR("PseudoregaliaTimerMod");
        ModVersion = STR("1.0");
        ModDescription = STR("Pseudoregalia Speedrun Timer Mod");
        ModAuthors = STR("highrow623");
        // Do not change this unless you want to target a UE4SS version
        // other than the one you're currently building with somehow.
        //ModIntendedSDKVersion = STR("2.6");
    }

    ~PseudoregaliaTimerMod() override
    {}

    auto on_unreal_init() -> void override
    {
        RC::Unreal::Hook::RegisterBeginPlayPostCallback([](RC::Unreal::AActor* actor) {
            ModHooks::RegisterActorHooks(actor);
            ModHooks::RunBeginPlayPostCallback(actor);
        });

        RC::Unreal::Hook::RegisterStaticConstructObjectPostCallback([](
            const RC::Unreal::FStaticConstructObjectParameters& params,
            RC::Unreal::UObject* object
        ) -> RC::Unreal::UObject* {
            ModHooks::RegisterObjectHooks(object);
            ModHooks::RunStaticConstructObjectPostCallback(object);
            return object;
        });
    }
};

#define PSEUDOREGALIA_TIMER_MOD_API __declspec(dllexport)
extern "C"
{
    PSEUDOREGALIA_TIMER_MOD_API RC::CppUserModBase* start_mod()
    {
        return new PseudoregaliaTimerMod();
    }

    PSEUDOREGALIA_TIMER_MOD_API void uninstall_mod(RC::CppUserModBase* mod)
    {
        delete mod;
    }
}
