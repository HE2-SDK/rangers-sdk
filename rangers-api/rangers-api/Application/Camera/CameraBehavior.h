#pragma once

namespace app::camera{
    class CameraBehavior : public hh::fnd::ReferencedObject {
    public:
        app_cmn::camera::CameraFrame* cameraFrame;
        char unk0;

        virtual void UnkFunc0(int64_t a2);
        virtual void UnkFunc1(int64_t a2) = 0;

        CameraBehavior(csl::fnd::IAllocator* allocator);
    };
}
