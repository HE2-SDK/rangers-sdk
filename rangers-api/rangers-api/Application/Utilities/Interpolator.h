#pragma once

namespace app::ut {
    template<typename T>
    class Interpolator {
    public:
        typedef T InterpolationFunc(T* from, T* to, float ratio);

        InterpolationFunc* interpolationFunc;
        csl::ut::MoveArray<T> values;
    };
}
