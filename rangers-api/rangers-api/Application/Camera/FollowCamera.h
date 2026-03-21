#pragma once

namespace app::camera {
    class FollowCamera : public app_cmn::camera::CameraController {
    public:
        struct SetupInfo {
            csl::math::Vector3 unk1;
            float unk2;
            csl::math::Vector3 unk3;
            float unk4;
            csl::math::Vector3 unk5;
            uint8_t unk6;
        };

        uint64_t qwordD0;
        float qwordD8;
        uint32_t qwordDC;
        float dwordE0;
        csl::math::Vector4 owordF0;
        uint32_t dword100;
        csl::math::Vector4 oword110;
        uint8_t byte120;

        DEFAULT_CREATE_FUNC(FollowCamera);

        virtual const char* GetControllerName() const override;
        virtual void UnkFunc2(int64_t a2) override;
        virtual int64_t UnkFunc3() override;

        void Setup(const SetupInfo& setupInfo);
    };
}
