#pragma once

#include "ModHooks.hpp"

#include "Unreal/UClass.hpp"

#include "Logger.hpp"

namespace {
    typedef RC::Unreal::UnrealScriptFunctionCallableContext CallableContext;
    auto nop = [](CallableContext&, void*) {};

    typedef RC::Unreal::UnrealScriptFunctionCallable Callable;
    struct ModHook
    {
        std::wstring _class_name;
        std::wstring _function_name;
        Callable _pre = nop;
        Callable _post = nop;
        bool _hooked = false;

        ModHook(std::wstring class_name, std::wstring function_name)
            : _class_name(class_name), _function_name(function_name)
        {}
    };

    std::array<ModHook, 0> actor_hooks = {};

    std::array<ModHook, 0> object_hooks = {};

    typedef std::function<void(RC::Unreal::AActor*)> ActorCallback;
    const std::unordered_map<std::wstring, ActorCallback> begin_play_post_callbacks = {};

    typedef std::function<void(RC::Unreal::UObject*)> ObjectCallback;
    const std::unordered_map<std::wstring, ObjectCallback> static_construct_object_post_callbacks = {};

    void RegisterModHook(RC::Unreal::UObject*, ModHook&);
} // namespace

void ModHooks::RegisterActorHooks(RC::Unreal::AActor* actor)
{
    for (auto& hook : actor_hooks)
    {
        if (hook._hooked) continue;
        if (actor->GetClassPrivate()->GetName() != hook._class_name) continue;
        RegisterModHook(actor, hook);
    }
}

void ModHooks::RunBeginPlayPostCallback(RC::Unreal::AActor* actor)
{
    std::wstring class_name = actor->GetClassPrivate()->GetName();
    if (!begin_play_post_callbacks.contains(class_name)) return;

    const auto& callback = begin_play_post_callbacks.at(class_name);
    callback(actor);
}

void ModHooks::RegisterObjectHooks(RC::Unreal::UObject* object)
{
    std::wstring name = object->GetName();
    for (auto& hook : object_hooks)
    {
        if (hook._hooked) continue;
        // this function is used primarily to hook into widgets, which are created ad hoc and so their names look
        // like {class_name}_{numbers}. since this function is called in StaticConstructObjectPostCallback, the
        // blueprint itself will also be passed to this function when loaded, and its name looks like {class_name}.
        // tacking on the underscore at the end filters this out.
        if (!name.starts_with(hook._class_name + L"_")) continue;
        RegisterModHook(object, hook);
    }
}

void ModHooks::RunStaticConstructObjectPostCallback(RC::Unreal::UObject* object)
{
    std::wstring name = object->GetName();
    for (const auto& [class_name, callback] : static_construct_object_post_callbacks)
    {
        if (!name.starts_with(class_name + L"_")) continue;
        callback(object);
        return;
    }
}

namespace
{

void RegisterModHook(RC::Unreal::UObject* object, ModHook& hook)
{
    RC::Unreal::UFunction* func = object->GetFunctionByName(hook._function_name.c_str());
    if (!func)
    {
        Log(L"Could not find function \"" + hook._function_name + L"\" in " + hook._class_name, LogType::Error);
        return;
    }
    Log(L"Establishing hook for \"" + hook._function_name + L"\" in " + hook._class_name, LogType::Loud);
    RC::Unreal::UObjectGlobals::RegisterHook(func, hook._pre, hook._post, nullptr);
    hook._hooked = true;
}

} // namespace
