#pragma once

#include <string>

namespace Trigger
{
    void EnterZone(std::wstring);
    void GetMajorKey(int32_t);
    void TouchSmallKey(std::wstring);
    void GetSmallKey();
    void TouchHealthPiece(std::wstring);
    void GetHealthPiece();
    void TouchUpgrade(std::wstring);
    void GetUpgrade();
    void TouchTransition(std::wstring);
    void Reset();
}
