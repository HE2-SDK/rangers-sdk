#pragma once

#define NEEDLE_RESOURCE_PT_ANIMATION 0x30304D494E415450ui64 // '00MINATP'

namespace hh::needle {
    class PtAnimationResource : public TNeedleRefcountResource<NEEDLE_RESOURCE_PT_ANIMATION, NeedleRefcountResource> {
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_PT_ANIMATION;

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

            unsigned int infoCount;
            FrameInfo* infos;
            CNameIDObject* name;
        };

        float start;
        float end;
        float fps;
        CNameIDObject* materialName;
        unsigned int textureNameCount;
        CNameIDObject** textureNames;
        unsigned int animationCount;
        Animation** animations;

        virtual void* QueryResource(size_t id) override;
        virtual const void* QueryResource(size_t id) const override;
    };

    PtAnimationResource* LoadPatternChangeAnimation(RenderingDevice* device, const void* data);

    struct AnimTexPatResult {
        int unk0;
    };

    int CalcPatternChangeAnimation(const PtAnimationResource::Animation* animation, float time);

    class AnimTexPatControl : public MirageAnimController<int, AnimTexPatResult> {
    public:
        typedef int ID;
        typedef AnimTexPatResult Result;

        struct Description {
            intrusive_ptr<PtAnimationResource> resource;
            hh::needle::Texture** textures;
            unsigned int textureCount;
        };

        int flags;
        intrusive_ptr<MeshResource> mesh;
        intrusive_ptr<PtAnimationResource> resource;
        hh::needle::Texture** textures;
        unsigned int animationCount;
        int unk4;
        int64_t unk5;

        static AnimTexPatControl* Create(Description& desc);

        virtual bool GetResult(int* idx, AnimTexPatResult* ret) override;
        virtual void Bind(intrusive_ptr<MeshResource>& meshResource);
        virtual void Unbind();
    };
}
