#pragma once

namespace Cyan{
    struct EmitParam {
        csl::math::Matrix44 emissionMatrix;
        csl::math::Vector3 emissionPosition;
        csl::math::Vector3 velocity;
        csl::math::Vector3 velocityDirection;
        csl::math::Vector3 accelerationDirection;
    };
}
