#pragma once

namespace hh::ui {
    class UICastListener : public SurfRide::CastListener {
    public:
        virtual void Unk9(int64_t a2, float a3, float a4) = 0;
    };
}
