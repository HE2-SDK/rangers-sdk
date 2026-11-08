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

        PlayerSpeedParam* GetSpeedParam() const;
        PlayerExtraParam* GetExtraParam() const;
        void LoadSpeedAndExtraParameters();
        void SetNeutralDecelerationRate(unsigned char value);

        bool IsFixed() const;
        Player* GetPlayerObject() const;
        bool IsGrounded() const;
        GOCPlayerKinematicParams::GroundInfo& GetGroundInfo() const;
        hh::path::PathEvaluator& GetPathEvaluator(int index) const;
        bool IsBoosting() const;

        PlayerPostureContext(csl::fnd::IAllocator* allocator, Player* player);
    };

    class PlayerPosture : public game::PostureBase<PlayerPostureContext> {};
}
