#pragma once

namespace app::evt{
    class EventEnvironmentCameraInterpolate : public EventEnvironment{
    public:
        hh::fnd::Reference<app_cmn::camera::CameraController> controller;
        float interpolateTime;
        char flags;

        virtual int64_t GetID() const override;
        virtual void EE_UnkFunc4() override;
        virtual void EE_UnkFunc5() override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual int EE_UnkFunc14() override;

        EventEnvironmentCameraInterpolate(csl::fnd::IAllocator* allocator);
    };
}
