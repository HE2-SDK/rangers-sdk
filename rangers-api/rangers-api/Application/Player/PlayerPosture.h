#pragma once

namespace app::player {
    class Player;
    class PlayerPostureContext : public hh::fnd::BaseObject {
    public:
        Player* player;
        GOCPlayerKinematicParams* gocPlayerKinematicParams;
        GOCPlayerBlackboard* gocPlayerBlackboard;
        BlackboardStatus* blackboardStatus;
        PlayerSpeedParam* speedParam;
        PlayerExtraParam* extraParam;
        PlayerGrindSpeedParam* grindSpeedParam;
        uint8_t unk1;
        unsigned char neutralDecelerationRate;

        CREATE_FUNC(PlayerPostureContext, Player* player);

        PlayerSpeedParam* GetSpeedParam() const;
        PlayerExtraParam* GetExtraParam() const;
        void LoadSpeedAndExtraParameters();
        void SetNeutralDecelerationRate(unsigned char value);
    };

    class PlayerPosture : public game::PostureBase<PlayerPostureContext> {};
}
