// Copyright (c) 2022 by Apex.AI Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#ifndef IOX_HOOFS_PLATFORM_BUILDING_BLOCKS_LOGCOMMON_INL
#define IOX_HOOFS_PLATFORM_BUILDING_BLOCKS_LOGCOMMON_INL

#include "iceoryx_hoofs/log/platform_building_blocks/logcommon.hpp"

#include <atomic>
#include <cstdint>
#include <cstring>
#include <mutex>

namespace iox
{
namespace pbb
{
inline constexpr const char* asStringLiteral(const LogLevel value) noexcept
{
    switch (value)
    {
    case LogLevel::OFF:
        return "LogLevel::OFF";
    case LogLevel::FATAL:
        return "LogLevel::FATAL";
    case LogLevel::ERROR:
        return "LogLevel::ERROR";
    case LogLevel::WARN:
        return "LogLevel::WARN";
    case LogLevel::INFO:
        return "LogLevel::INFO";
    case LogLevel::DEBUG:
        return "LogLevel::DEBUG";
    case LogLevel::TRACE:
        return "LogLevel::TRACE";
    }

    return "[Undefined LogLevel]";
}

inline constexpr const char* logLevelDisplayColor(const LogLevel value) noexcept
{
    switch (value)
    {
    case LogLevel::OFF:
        return ""; // nothing
    case LogLevel::FATAL:
        return "\033[0;1;97;41m"; // bold bright white on red
    case LogLevel::ERROR:
        return "\033[0;1;31;103m"; // bold red on light yellow
    case LogLevel::WARN:
        return "\033[0;1;93m"; // bold bright yellow
    case LogLevel::INFO:
        return "\033[0;1;92m"; // bold bright green
    case LogLevel::DEBUG:
        return "\033[0;1;96m"; // bold bright cyan
    case LogLevel::TRACE:
        return "\033[0;1;36m"; // bold cyan
    }

    return ""; // nothing
}

inline constexpr const char* logLevelDisplayText(const LogLevel value) noexcept
{
    switch (value)
    {
    case LogLevel::OFF:
        return "[ Off ]";
    case LogLevel::FATAL:
        return "[Fatal]";
    case LogLevel::ERROR:
        return "[Error]";
    case LogLevel::WARN:
        return "[Warn ]";
    case LogLevel::INFO:
        return "[Info ]";
    case LogLevel::DEBUG:
        return "[Debug]";
    case LogLevel::TRACE:
        return "[Trace]";
    }

    return "[UNDEF]";
}
} // namespace pbb
} // namespace iox

#endif // IOX_HOOFS_PLATFORM_BUILDING_BLOCKS_LOGCOMMON_INL
