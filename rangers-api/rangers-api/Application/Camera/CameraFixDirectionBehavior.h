#pragma once

namespace app::camera {
    class CameraFixDirectionBehavior : public CameraBehavior {
    public:
        csl::math::Vector4 vector30;
        char byte40;

        virtual void UnkFunc1(int64_t a2) override;

        CameraFixDirectionBehavior(csl::fnd::IAllocator* allocator, char byte40);
    };
}
