#pragma once

namespace app::dlc {
    enum class DLCType : unsigned char {
        PREORDER,
        DELUXE,
        MONSTERHUNTER,
        KOCOTOY,
        KORONE,
        SOAPSHOES = 7,
        XMAS
    };

    class DLCManagerSteam {
    public:
        bool IsDLCAvailable(DLCType dlcType);
    };

    bool IsDLCAvailable(hh::game::GameManager* gameManager, DLCType dlcType);
}
