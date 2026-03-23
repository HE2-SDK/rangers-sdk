#pragma once

namespace hh::needle {
    struct FxLightParam {
        float color[3];
        float unk1;
        csl::math::Position position;
        float attenuationRadius;
        csl::math::Position direction;
        float radius;
        float attenuationStart;
        float attenuationEnd;
        float unused;
        float shadowing;
    };
}
