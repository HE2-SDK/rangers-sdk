#pragma once

namespace app::camera {
    class MotionCamera : public app_cmn::camera::CameraController {
    public:
        struct Description{
            hh::gfx::ResAnimCameraContainer* resAnimCamera;
            csl::math::Transform animTransform;
            hh::fnd::HFrame* attachPoint;
            bool unk1;
            bool unk1b;
            bool unk1c;
            bool unk1d;
            char unk2;

            Description();
        };

        csl::ut::MoveArray<hh::needle::intrusive_ptr<hh::needle::AnimCameraControl>> animCamControls;
        csl::math::Transform animTransform;
        hh::fnd::Reference<hh::fnd::HFrame> attachPoint;
        unsigned int currentAnimCam;
        unsigned char flags;

        virtual const char* GetControllerName() const override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void UnkFunc2(int64_t a2) override;
        virtual int64_t UnkFunc3() override;

        void Setup(const Description& desc);

        MotionCamera(csl::fnd::IAllocator* allocator);
    };
};
