#pragma once

#define NEEDLE_RESOURCE_VIS_ANIMATION 0x304D494E41534956ui64 // '0MINASIV'

namespace hh::needle {
    class VisibilityAnimationResource : public TNeedleRefcountResource<NEEDLE_RESOURCE_VIS_ANIMATION, NeedleRefcountResource> {
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_VIS_ANIMATION;

        struct Animation {
            struct FrameInfo {
                struct Keyframe {
                    float keyframe;
                    float value;
                };

                unsigned int type; // unused
                unsigned int count;
                Keyframe* keyframes;
            };

            float unk0; // unused
            float start;
            float end;
            float fps;
            unsigned int infoCount;
            FrameInfo* infos;
            CNameIDObject* name;
        };

        unsigned int animationCount;
        int64_t unk0;
        Animation* animations;

        virtual void* QueryResource(size_t id) override;
        virtual const void* QueryResource(size_t id) const override;
    };

    VisibilityAnimationResource* LoadVisibilityAnimation(RenderingDevice* device, const void* data);

    struct AnimVisResult {
        bool isVisible;
    };

    void CalcVisibilityNodeAnimation(const VisibilityAnimationResource::Animation* animation, float time, bool* retVisible);

    class NameIDRef;

    class AnimVisControl : public MirageAnimController<NameIDRef, AnimVisResult> {
    public:
        typedef NameIDRef ID;
        typedef AnimVisResult Result;
        
        int flags;
        unsigned int animationCount;
        int64_t unk0;
        int64_t unk1;
        intrusive_ptr<VisibilityAnimationResource> resource;

        static AnimVisControl* Create(intrusive_ptr<VisibilityAnimationResource>& resource);

        virtual bool GetResult(NameIDRef* idx, AnimVisResult* ret) override;
    };
}
