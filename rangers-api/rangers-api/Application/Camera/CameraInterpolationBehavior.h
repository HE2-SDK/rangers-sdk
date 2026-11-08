#pragma once

namespace app::camera {
    class CameraInterplationBehavior : public CameraBehavior {
    public:
        int64_t qword28;
        int64_t qword30;
        csl::math::Vector4 oword40;
        int64_t qword50;
        int64_t qword58;
        int64_t qword60;
        int dword68;
        char byte6C;
        char byte6D;

        virtual void UnkFunc0(int64_t a2) override;
        virtual void UnkFunc1(int64_t a2) override;

        CameraInterplationBehavior(csl::fnd::IAllocator* allocator, char byte40);
    };
}
