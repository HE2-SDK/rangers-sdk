#pragma 

namespace Cyan {
    unsigned short ConvertToHalfFloat(float value);

    template<typename T>
    class MemObject {
    public:
        T* object;
    };

    struct Matrix23 {
        csl::math::Vector3 x;
        csl::math::Vector3 y;
    };
}
