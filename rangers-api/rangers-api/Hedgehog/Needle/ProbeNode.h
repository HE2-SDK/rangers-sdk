#pragma once

namespace hh::needle {
    class ProbeNode : public NeedleRefcountObject {
    public:
        enum class Flags : unsigned int {
            USE_RADIUS_SCALING,
            UNK0,
            IS_OBB_SHAPE
        };

        csl::geom::Aabb aabb;
        csl::math::Position extents;
        float index;
        csl::ut::Bitset<Flags> flags;
        float radius;
        float maxExtent; // maximum scale along all axes
        float dword4C;
        uint64_t qword50;
        uint64_t qword58;
        uint64_t qword60;
        uint64_t qword68;
        uint64_t qword70;
        uint64_t qword78;
        uint64_t qword80;
        uint64_t qword88;
        uint64_t qword90;
        uint64_t qword98;
        uint64_t qwordA0;
        uint64_t qwordA8;
        uint64_t qwordB0;
        uint64_t qwordB8;
        uint64_t qwordC0;
        uint64_t qwordC8;
        uint64_t qwordD0;
        uint64_t qwordD8;
        uint64_t qwordE0;
        uint64_t qwordE8;
        uint64_t qwordF0;
        uint64_t qwordF8;
        uint64_t qword100;
        uint64_t qword108;
        uint64_t qword110;
        uint64_t qword118;
        float aabbScale; // distance between max and min of aabb
        intrusive_ptr<hh::needle::Texture> texture1;
        int width;
        int height;
        csl::ut::VariableString textureName;
        csl::ut::VariableString resourceName;
        intrusive_ptr<hh::needle::Texture> texture2;
        bool bool160;
        uint8_t word161;
        uint32_t dword164;
        volatile int dword168;
        uint8_t byte16C;

        DEFAULT_CREATE_FUNC(ProbeNode);
    };
}
