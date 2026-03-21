#pragma once

namespace app::camera {
    class StandardCamera : public app_cmn::camera::CameraController {
    public:
        struct SetupInfo {
            heur::rfl::StandardCameraConfig* config;
            uint16_t unk1;

            SetupInfo();
        };

        uint64_t qwordD0;
        uint64_t qwordD8;
        uint64_t qwordE0;
        uint64_t qwordE8;
        hh::fnd::Reference<hh::ut::StateManager> phh__ut__statemanagerF0;
        hh::ut::HsmBase hh__ut__hsmbaseF8;
        uint32_t dword168;

        DEFAULT_CREATE_FUNC(StandardCamera);

        virtual const char* GetControllerName() const override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void UnkFunc2(int64_t a2) override;
        virtual int64_t UnkFunc3() override;
        virtual void UnkFunc4() override;
        virtual void UnkFunc5() override;

        void Setup(const SetupInfo& setupInfo);
    };
}
