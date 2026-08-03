#pragma once

#define NEEDLE_RESOURCE_CAMERA_MOTION 0x304D494E414D4143ui64 // '0MINAMAC'

namespace hh::needle {
    class CameraMotionResource : public TNeedleRefcountResource<NEEDLE_RESOURCE_CAMERA_MOTION, NeedleRefcountResource> {
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_CAMERA_MOTION;

        struct Animation {
            struct FrameInfo {
                struct Keyframe {
                    float keyframe;
                    float value;
                };

                enum class Type : unsigned int {
                    POS_X,
                    POS_Y,
                    POS_Z,
                    ROT_X,
                    ROT_Y,
                    ROT_Z,
                    AIM_X,
                    AIM_Y,
                    AIM_Z,
                    TWIST,
                    ZNEAR,
                    ZFAR,
                    FOV,
                    ASPECT_RATIO
                };

                Type type;
                int flags; // unused(?)
                unsigned int count;
                Keyframe* keyframes;
            };

            enum class RotationOrder : unsigned int {
                YZX,
                ZYX,
                XZY,
                ZXY,
                XYZ,
                YXZ
            };

            CNameIDObject* name;
            bool useAimPos;
            RotationOrder rotOrder;
            float fps;
            float start;
            float end;
            ViewParameter viewParam;
            ProjParameter projParam;
            unsigned int infoCount;
            FrameInfo* infos;
        };

        unsigned int animationCount;
        Animation* animations;

        virtual void* QueryResource(size_t id) override;
        virtual const void* QueryResource(size_t id) const override;
        void FixScale(float scale);
    };

    CameraMotionResource* LoadCameraMotion(const void* data);
    CameraMotionResource* LoadCameraMotion(RenderingDevice* device, const void* data);
    void CalcCameraAnimation(const CameraMotionResource* resource, unsigned int idx, float time, ViewParameter* viewParam, ProjParameter* projParam);    

    class AnimCameraControl : public AnimController, public NeedleRefcountObject {
    public:
        unsigned int idx;
        intrusive_ptr<CameraMotionResource> resource;
    
        static AnimCameraControl* Create(intrusive_ptr<CameraMotionResource>& resource, unsigned int idx);

        virtual void GetResult(csl::math::Matrix34* viewMat, csl::math::Matrix44* projMat);
        virtual void GetResult(ViewParameter* viewParam, ProjParameter* projParam);
    };
}
