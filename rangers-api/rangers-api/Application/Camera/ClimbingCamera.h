#pragma once

namespace app::camera {
    class ClimbingCamera : public app_cmn::camera::CameraController {
    public:
        struct Unk1 {
            uint32_t unk1;
            uint8_t unk2;

            Unk1();
        };

        Unk1 unkD0;
        csl::math::Matrix34 csl__math__matrix34E0;
        csl::math::Vector4 csl__math__vector4120;
        csl::math::Vector4 csl__math__vector4130;
        csl::math::Vector4 csl__math__vector4140;
        csl::math::Vector4 oword150;
        csl::math::Vector4 oword160;
        uint64_t qword170;
        uint64_t qword178;
        float float180;
        float float184;
        uint32_t qword184;
        uint32_t dword18C;
        uint32_t dword190;
        uint16_t word194;
        uint8_t byte196;

        DEFAULT_CREATE_FUNC(ClimbingCamera);

        virtual const char* GetControllerName() const override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void UnkFunc2(int64_t a2) override;
        virtual int64_t UnkFunc3() override;
        virtual void UnkFunc4() override;
    };
}
