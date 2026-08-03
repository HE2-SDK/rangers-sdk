#pragma once

namespace app::player {
    class PlayerGrindSpeedParam : public hh::fnd::BaseObject {
    public:
        struct GrindSpeedParam {
            float min, max;
        };

        struct FullGrindSpeedParam {
            int id;
            GrindSpeedParam grindSpeedParam;
        };

        csl::ut::MoveArray<GrindSpeedParam> grindSpeedParams[2];

        PlayerGrindSpeedParam(csl::fnd::IAllocator* allocator);
    };
}
