#pragma once

namespace app::player {
    class PlayerSpeedParam : public hh::fnd::BaseObject {
    public:
        enum class Mode : unsigned int {
            NORMAL,
            BOOST,
            BOOST_LVMAX,
        };

        struct Params {
            float min;
            float max;
            float initial;
            float minTurn;
        };

        struct ParamData {
            uint32_t unk1;
            Params param1;
            Params param2;
        };

        csl::ut::MoveArray<ParamData> params[3];
        Params speedRates[3];
        float floatA0;
        float floatA4;
        float maxSpeedRate;
        csl::ut::InplaceMoveArray<void*, 4> unkB0;

        DEFAULT_CREATE_FUNC(PlayerSpeedParam);

        void LoadParams(unsigned int unkParam1, Mode mode, const Params& param1, const Params& param2);
        void SetMaxSpeedLimits(float min, float max);
        void SetMaxSpeedRate(Mode mode, float value);
        void SetInitialSpeedRate(Mode mode, float value);
        void SetMinTurnSpeedRate(Mode mode, float value);
        void SetMaxSpeedRate(float value);
    };
}
