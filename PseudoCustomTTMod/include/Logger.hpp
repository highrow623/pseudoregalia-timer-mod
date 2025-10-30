#pragma once

#include <string>

namespace Logger
{
    enum class LogType
    {
        Default,
        Loud,
        Warning,
        Error,
    };

    void Log(const std::wstring&, LogType = LogType::Default);
    void Log(const std::string&, LogType = LogType::Default);
    std::wstring ToWide(const std::string&);
}

using Logger::Log;
using Logger::LogType;
