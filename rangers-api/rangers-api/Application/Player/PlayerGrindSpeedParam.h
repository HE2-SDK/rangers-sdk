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
            unsigned int id;
            Params param;
        };

        csl::ut::MoveArray<ParamData> params[2];

        DEFAULT_CREATE_FUNC(PlayerGrindSpeedParam);

        void LoadParams(unsigned int id, Mode mode, const Params& param);
    };
}
