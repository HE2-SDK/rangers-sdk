#pragma once

namespace app::camera {
    class FocusFrameCamera : public app_cmn::camera::CameraController {
    public:
        struct Parameters {
            hh::fnd::Reference<hh::gfx::ModelNodeHFrame> focusFrame;
            float dwordD8;
            float dwordDC;
            float dwordE0;
            float dwordE4;
            float dwordE8;
            csl::math::Vector4 csl__math__vector4F0; // offset?
            float dword100;
            float dword104;
            float dword108;
        };

        Parameters parameters;
        hh::fnd::Reference<CameraBoom> camBoom;
        hh::fnd::Reference<CameraFixDirectionBehavior> fixDirBehavior;
        hh::fnd::Reference<CameraInterplationBehavior> camInterpBehavior;

        virtual const char* GetControllerName() const override;
        virtual void UnkFunc2(int64_t a2) override;
        virtual int64_t UnkFunc3() override;

        FocusFrameCamera(csl::fnd::IAllocator* allocator);
        void SetParameters(const Parameters& params);
    };
}
