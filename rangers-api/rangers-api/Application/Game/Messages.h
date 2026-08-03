#pragma once

namespace app::game {
    class MsgNotifyLevelStatus : public hh::fnd::Message {
    public:
        uint32_t status;
        uint16_t unk1;
        uint8_t unk2;
    };

    // Recipients: Game
    class MsgChangeLayerTimeScale : public app::fnd::AppMessage<MsgChangeLayerTimeScale> {
    public:
        char interpolatorId[16];
        float timeScale;
        uint32_t layerMask;
        uint32_t unk1{};
        bool unk2{};

        inline MsgChangeLayerTimeScale(const char* interpolatorId, uint32_t layerMask, float timeScale) : fnd::AppMessage<MsgChangeLayerTimeScale>{ hh::fnd::MessageID::CHANGE_LAYER_TIME_SCALE }, layerMask{ layerMask }, timeScale{ timeScale } {
            strncpy(this->interpolatorId, interpolatorId, sizeof(this->interpolatorId));
        }
    };

    // Recipients: Game
    class MsgChangeGlobalTimeScale : public app::fnd::AppMessage<MsgChangeGlobalTimeScale> {
    public:
        char interpolatorId[16];
        float timeScale;
        uint32_t unk1{};

        inline MsgChangeGlobalTimeScale(const char* interpolatorId, float timeScale) : fnd::AppMessage<MsgChangeGlobalTimeScale>{ hh::fnd::MessageID::CHANGE_GLOBAL_TIME_SCALE }, timeScale{ timeScale } {
            strncpy(this->interpolatorId, interpolatorId, sizeof(this->interpolatorId));
        }
    };

    // Recipients: Game
    class MsgRevertLayerTimeScale : public app::fnd::AppMessage<MsgRevertLayerTimeScale> {
    public:
        char interpolatorId[16];
        uint32_t layerMask;
        int unk2{};

        inline MsgRevertLayerTimeScale(const char* interpolatorId, uint32_t layerMask) : fnd::AppMessage<MsgRevertLayerTimeScale>{ hh::fnd::MessageID::REVERT_LAYER_TIME_SCALE }, layerMask{ layerMask } {
            strncpy(this->interpolatorId, interpolatorId, sizeof(this->interpolatorId));
        }
    };

    // Recipients: Game
    class MsgRevertGlobalTimeScale : public app::fnd::AppMessage<MsgRevertGlobalTimeScale> {
    public:
        char interpolatorId[16];
        int unk2{};

        inline MsgRevertGlobalTimeScale(const char* interpolatorId) : fnd::AppMessage<MsgRevertGlobalTimeScale>{ hh::fnd::MessageID::REVERT_GLOBAL_TIME_SCALE } {
            strncpy(this->interpolatorId, interpolatorId, sizeof(this->interpolatorId));
        }
    };

    class MsgTransitCyberStage : public app::fnd::AppMessage<MsgTransitCyberStage> {
    public:
        const char* stageCode;
        int64_t unk0{ 0 };
        char unk1{ 0 };
        hh::fnd::WorldPosition openZoneSonicPos{};
        int portalNo{ 0 };
        char unk2{ 0 };

        MsgTransitCyberStage() : fnd::AppMessage<MsgTransitCyberStage>{ hh::fnd::MessageID::TRANSIT_CYBER_STAGE } {}
    };

    class MsgTransitIslandStage : public app::fnd::AppMessage<MsgTransitIslandStage> {
    public:
        const char* stageCode;
        int64_t unk0{ 0 };
        char unk1{ 0 };

        MsgTransitIslandStage() : fnd::AppMessage<MsgTransitIslandStage>{ hh::fnd::MessageID::TRANSIT_ISLAND_STAGE } {}
    };

    class MsgSetMenuEnabled : public app::fnd::AppMessage<MsgSetMenuEnabled> {
    public:
        int unk0{ 0 };
        int nameHash{ 0 };
        char unk1{ 0 };

        MsgSetMenuEnabled() : fnd::AppMessage<MsgSetMenuEnabled>{ hh::fnd::MessageID::SET_MENU_ENABLED } {}
    };

    class MsgSetMenuLimitedEnabled : public app::fnd::AppMessage<MsgSetMenuLimitedEnabled> {
    public:
        char unk0{ 0 };

        MsgSetMenuLimitedEnabled() : fnd::AppMessage<MsgSetMenuLimitedEnabled>{ hh::fnd::MessageID::SET_MENU_LIMITED_ENABLED } {}
    };

    class MsgScriptExit : public app::fnd::AppMessage<MsgScriptExit> {
    public:
        MsgScriptExit() : fnd::AppMessage<MsgScriptExit>{ hh::fnd::MessageID::SCRIPT_EXIT } {}
    };

    class MsgShowKodama : public app::fnd::AppMessage<MsgShowKodama> {
    public:
        MsgShowKodama() : fnd::AppMessage<MsgShowKodama>{ hh::fnd::MessageID::SHOW_KODAMA } {}
    };

    class MsgHideKodama : public app::fnd::AppMessage<MsgHideKodama> {
    public:
        MsgHideKodama() : fnd::AppMessage<MsgHideKodama>{ hh::fnd::MessageID::HIDE_KODAMA } {}
    };

    class MsgChangePlayerCharacter : public app::fnd::AppMessage<MsgChangePlayerCharacter> {
    public:
        player::CharacterIdU8 newCharId{ player::CharacterIdU8::SONIC };
        bool startCharactersBgm{ false };

        MsgChangePlayerCharacter() : fnd::AppMessage<MsgChangePlayerCharacter>{ hh::fnd::MessageID::CHANGE_PLAYER_CHARACTER } {}
    };
}
