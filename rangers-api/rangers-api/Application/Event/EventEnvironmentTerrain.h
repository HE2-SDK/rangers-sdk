#pragma once

namespace app::evt {
    class EventEnvironmentTerrain : public EventEnvironment {
    public:
        hh::fnd::Reference<app_cmn::camera::CameraController> cameraController;
        int unk1;
        short unk2;

        EventEnvironmentTerrain(csl::fnd::IAllocator* allocator);

        virtual int64_t GetID() const override;
        virtual void EE_UnkFunc5() override;
        virtual void EE_UnkFunc7() override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void EE_UnkFunc10() override;
        virtual void EE_UnkFunc11() override;
        virtual int EE_UnkFunc14() override;
        virtual void EE_UnkFunc16() override;
    };
}
