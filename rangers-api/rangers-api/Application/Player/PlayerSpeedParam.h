#pragma once

namespace app::player {
    class PlayerSpeedParam : public hh::fnd::BaseObject {
    public:
        // Initialization in PlayerPostureContext ctor
        struct SpeedParam {
            float min, max;
            float initial;
            float minTurn;
        };

        struct FullSpeedParam {
            int id;
            SpeedParam speedParam1;
            SpeedParam speedParam2;
        };

        csl::ut::MoveArray<SpeedParam> speedParams[3];
        SpeedParam currentSpeedParams[3]; // struct guessed
        float optionMaxSpeedLimitMin;
        float optionMaxSpeedLimitMax;
        float dwordA8;
        csl::ut::InplaceMoveArray<int64_t, 4> qwordA0;

        float GetSpeed() const;

        PlayerSpeedParam(csl::fnd::IAllocator* allocator);
    };
}
