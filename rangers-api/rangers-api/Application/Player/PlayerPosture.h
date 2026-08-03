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

        PlayerPostureContext(csl::fnd::IAllocator* allocator, Player* playerObject);
    };

    class PlayerPosture : public game::PostureBase<PlayerPostureContext> {};
}