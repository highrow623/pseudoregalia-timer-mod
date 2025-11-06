#pragma once

#include "Logger.hpp"

#include <codecvt>

#include <DynamicOutput/DynamicOutput.hpp>

void Logger::Log(const std::wstring& message, LogType log_level)
{
    auto full_message = L"[PseudoregaliaTimerMod] " + message + L"\n";
    switch (log_level)
    {
    case LogType::Default:
        RC::Output::send<RC::LogLevel::Default>(full_message);
        break;
    case LogType::Loud:
        RC::Output::send<RC::LogLevel::Verbose>(full_message);
        break;
    case LogType::Warning:
        RC::Output::send<RC::LogLevel::Warning>(full_message);
        break;
    case LogType::Error:
        RC::Output::send<RC::LogLevel::Error>(full_message);
        break;
    }
}

void Logger::Log(const std::string& message, LogType log_level)
{
    Log(ToWide(message), log_level);
}

std::wstring Logger::ToWide(const std::string& input)
{
    static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes(input);
}
