#pragma once

namespace app::camera{
    class FollowCamera : public app_cmn::camera::CameraController {
    public:
        struct Parameters {
            float xRot;
            float yRot;
            float distance;
            float zRot;
            float fov;
            csl::math::Vector3 targetOffset;
            float gravityOffset;
            csl::math::Vector3 playerOffset;
            bool byte120;
        };

        Parameters params;

        virtual const char* GetControllerName() const override;
        virtual void UnkFunc2(int64_t a2) override;
        virtual int64_t UnkFunc3() override;

        FollowCamera(csl::fnd::IAllocator* allocator);
        void SetParameters(const Parameters& params);
    };
}
