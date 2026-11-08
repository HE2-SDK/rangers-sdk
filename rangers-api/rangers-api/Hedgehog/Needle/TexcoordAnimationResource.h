#pragma once

#define NEEDLE_RESOURCE_TEXCOORD_ANIMATION 0x30304D494E415655ui64 // '00MINAVU'

namespace hh::needle {
    class TexcoordAnimationResource : public TNeedleRefcountResource<NEEDLE_RESOURCE_TEXCOORD_ANIMATION, NeedleRefcountResource> {
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_TEXCOORD_ANIMATION;

        struct Animation {
            struct FrameInfo {
                struct Keyframe {
                    float keyframe;
                    float value;
                };

                enum class Type : unsigned char {
                    POS_X,
                    POS_Y,
                    ROTATION,
                    SCALE_X,
                    SCALE_Y
                };

                enum class Interpolation : unsigned char {
                    LINEAR,
                    CONSTANT
                };

                Type type;
                Interpolation interpolation;
                unsigned int count;
                Keyframe* keyframes;
            };

            unsigned int infoCount;
            FrameInfo* infos;
            unsigned int nameCount;
            CNameIDObject** names;
        };

        CNameIDObject* materialName;
        float start;
        float end;
        float fps;
        unsigned int animationCount;
        Animation** animations;

        virtual void* QueryResource(size_t id) override;
        virtual const void* QueryResource(size_t id) const override;
    };

    TexcoordAnimationResource* LoadTexcoordAnimation(RenderingDevice* device, const void* data);

    struct AnimTexSrtResult {
        unsigned int animCount;
        unsigned int inputCount;
        float maybeTime;
        CNameIDObject** inputNames;
        float affineMatrix2D[9];
    };

    void CalcTexcoordAnimation(const TexcoordAnimationResource::Animation* resource, float time, float* retMatrix);

    class AnimTexSrtControl : public MirageAnimController<int, AnimTexSrtResult> {
    public:
        typedef int ID;
        typedef AnimTexSrtResult Result;

        struct Anim {
            unsigned int animationIdx;
            unsigned int curFrame0;
            unsigned int curFrame1;
            int unk1;
            int unk2;
            int unk3;
            int unk4; // related to inputNames?
            unsigned int inputCountSet;
            CNameIDObject* inputNamesReserved[8];
            unsigned int inputCount;
            float maybeTime;
            CNameIDObject** inputNames;
            float affineMatrix2D[9];
        };

        unsigned int animationCount;
        unsigned int animCount;
        Anim* anims;
        int flags;
        intrusive_ptr<MeshResource> mesh;
        intrusive_ptr<TexcoordAnimationResource> resource;
        float unk4;
        int unk5;
        float unk6;
        int unk7;
        float unk8;
        int unk9;
        float unk10;
        int unk11;
        float unk12;

        static AnimTexSrtControl* Create(intrusive_ptr<TexcoordAnimationResource>& resource);

        virtual bool GetResult(int* idx, AnimTexSrtResult* ret) override;
    };
}
