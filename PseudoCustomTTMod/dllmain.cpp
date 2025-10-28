#include <Mod/CppUserModBase.hpp>
#include <DynamicOutput/DynamicOutput.hpp>

class PseudoCustomTTMod : public RC::CppUserModBase
{
public:
    PseudoCustomTTMod() : CppUserModBase()
    {
        ModName = STR("PseudoCustomTTMod");
        ModVersion = STR("1.0");
        ModDescription = STR("Pseudoregalia Custom Time Trials");
        ModAuthors = STR("highrow623");
        // Do not change this unless you want to target a UE4SS version
        // other than the one you're currently building with somehow.
        //ModIntendedSDKVersion = STR("2.6");
        
        RC::Output::send<RC::LogLevel::Verbose>(L"[PseudoCustomTTMod] mod initialized\n");
    }

    ~PseudoCustomTTMod() override
    {
    }

    auto on_update() -> void override
    {
    }
};

#define PSEUDO_CUSTOM_TT_MOD_API __declspec(dllexport)
extern "C"
{
    PSEUDO_CUSTOM_TT_MOD_API RC::CppUserModBase* start_mod()
    {
        return new PseudoCustomTTMod();
    }

    PSEUDO_CUSTOM_TT_MOD_API void uninstall_mod(RC::CppUserModBase* mod)
    {
        delete mod;
    }
}
