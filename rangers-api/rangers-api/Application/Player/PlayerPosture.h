#pragma once

namespace app::player {
    class PlayerPostureContext : public hh::fnd::BaseObject {
    public:
        Player* playerObject;
        GOCPlayerKinematicParams* gocPlayerKinematicParams;
        GOCPlayerBlackboard* gocPlayerBlackboard;
        BlackboardStatus* blackboardStatus;
        PlayerSpeedParam* speedParam;
        PlayerExtraParam* extraParam;
        PlayerGrindSpeedParam* grindSpeedParam;
        short word48;

        bool IsFixed() const;
        Player* GetPlayerObject() const;
        bool IsGrounded() const;
        GOCPlayerKinematicParams::GroundInfo& GetGroundInfo() const;
        hh::path::PathEvaluator& GetPathEvaluator(int index) const;
        bool IsBoosting() const;

        PlayerPostureContext(csl::fnd::IAllocator* allocator, Player* playerObject);
    };

    class PlayerPosture : public game::PostureBase<PlayerPostureContext> {};
}