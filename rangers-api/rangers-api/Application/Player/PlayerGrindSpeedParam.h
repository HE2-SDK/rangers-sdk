#pragma once

namespace app::player {
    class PlayerGrindSpeedParam : public hh::fnd::BaseObject {
    public:
        enum class Mode : unsigned int {
            NORMAL,
            BOOST,
        };

        struct Params {
            float minSpeed;
            float maxSpeed;
        };

        struct ParamData {
            uint32_t unk1;
            Params param;
        };

        csl::ut::MoveArray<ParamData> params[2];

        DEFAULT_CREATE_FUNC(PlayerGrindSpeedParam);

        void LoadParams(unsigned int unkParam1, Mode mode, const Params& param);
    };
}
