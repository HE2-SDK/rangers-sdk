#pragma once

namespace app::player {
    class PlayerExtraParam : public hh::fnd::BaseObject {
    public:
        struct ExtraParam {
            float force;
            float baseRotateForce;
            float gravityScale;
            float baseAirDragScaleMin;
        };

        struct FullExtraParam {
            int id;
            ExtraParam extraParam1;
            ExtraParam extraParam2;
        };

        csl::ut::MoveArray<FullExtraParam> extraParams;
        ExtraParam currentExtraParam;

        PlayerExtraParam(csl::fnd::IAllocator* allocator);
    };
}
