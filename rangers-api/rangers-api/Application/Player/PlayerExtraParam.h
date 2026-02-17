#pragma once

namespace app::player {
    class PlayerExtraParam : public hh::fnd::BaseObject {
    public:
        struct Params {
            float acceleForce;
            float rotateForce;
            float gravitySize;
            float baseAirDragScaleMax;
        };

        struct ParamData {
            uint32_t unk1;
            Params param1;
            Params param2;
        };

        csl::ut::MoveArray<ParamData> params;
        Params rates;

        DEFAULT_CREATE_FUNC(PlayerExtraParam);

        void LoadParams(unsigned int unkParam1, const Params& params1, const Params& params2);
        void SetAcceleForceRate(float value);
        void SetRotateForceRate(float value);
        void SetGravityRate(float value);
        void SetBaseAirDragScaleRate(float value);
    };
}
