#pragma once

namespace app::player {
    class PlayerPostureContext;
    class GOCPlayerPosture : public hh::game::GOComponent {
    public:
        struct SetupInfo {
            PlayerPostureContext* context;
        };

        PlayerPostureContext* context;
        void* postureManager;
        void* postureInputManager;
        uint8_t unk204;

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerPosture);

        void Setup(const SetupInfo& setupInfo);
    };
}