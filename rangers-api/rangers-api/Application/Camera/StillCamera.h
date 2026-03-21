#pragma once

namespace app::camera {
    class StillCamera : public app_cmn::camera::CameraController {
    public:
        csl::math::Vector4 csl__math__vector4D0;
        csl::math::Vector4 csl__math__vector4E0;
        uint32_t dwordF0;

        DEFAULT_CREATE_FUNC(StillCamera);

        virtual const char* GetControllerName() const override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual int64_t UnkFunc3() override;
    };
}
