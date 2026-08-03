#pragma once

#define NEEDLE_RESOURCE_MATERIAL_ANIMATION 0x304D494E4154414Dui64 // '0MINATAM'

namespace hh::needle {
    class MaterialAnimationResource : public TNeedleRefcountResource<NEEDLE_RESOURCE_MATERIAL_ANIMATION, NeedleRefcountResource> {
    public:
        static size_t constexpr resourceId = NEEDLE_RESOURCE_MATERIAL_ANIMATION;

        struct FrameInfo {
            struct Keyframe {
                float keyframe;
                float value;
            };

            enum class Type : unsigned char {
                DIFFUSE_X,
                DIFFUSE_Y,
                DIFFUSE_Z,
                DIFFUSE_W,

                AMBIENT_X,
                AMBIENT_Y,
                AMBIENT_Z,
                AMBIENT_W,

                SPECULAR_X,
                SPECULAR_Y,
                SPECULAR_Z,
                SPECULAR_W,

                EMISSIVE_X,
                EMISSIVE_Y,
                EMISSIVE_Z,
                EMISSIVE_W,

                OPACITY_REFLECTION_X,
                OPACITY_REFLECTION_Y,
                OPACITY_REFLECTION_Z,
                OPACITY_REFLECTION_W
            };

            Type type;
            unsigned int count;
            Keyframe* keyframes;
        };

        unsigned int frameInfoCount;
        FrameInfo* frameInfos;
        float start;
        float end;
        float fps;
        CNameIDObject* materialName;

        virtual void* QueryResource(size_t id) override;
        virtual const void* QueryResource(size_t id) const override;
    };

    MaterialAnimationResource* LoadMaterialAnimation(RenderingDevice* device, const void* data);

    struct MaterialColorData {
        // color names from 0x14100CD20
        float diffuseColor[4];
        float ambientColor[4];
        float specularColor[4];
        float emissiveColor[4];
        float opacityReflectionRefractionSpectype[4];
        float unk0[4]; // unused
    };

    enum class CalcMatAnimResult : unsigned int {
        HAS_DIFFUSE_X = 1 << 0,
        HAS_DIFFUSE_Y = 1 << 1,
        HAS_DIFFUSE_Z = 1 << 2,
        HAS_DIFFUSE_W = 1 << 3,

        HAS_AMBIENT_X = 1 << 4,
        HAS_AMBIENT_Y = 1 << 5,
        HAS_AMBIENT_Z = 1 << 6,
        HAS_AMBIENT_W = 1 << 7,

        HAS_SPECULAR_X = 1 << 8,
        HAS_SPECULAR_Y = 1 << 9,
        HAS_SPECULAR_Z = 1 << 10,
        HAS_SPECULAR_W = 1 << 11,

        HAS_EMISSIVE_X = 1 << 12,
        HAS_EMISSIVE_Y = 1 << 13,
        HAS_EMISSIVE_Z = 1 << 14,
        HAS_EMISSIVE_W = 1 << 15,

        HAS_OPACITY_REFLECTION_X = 1 << 16,
        HAS_OPACITY_REFLECTION_Y = 1 << 17,
        HAS_OPACITY_REFLECTION_Z = 1 << 18,
        HAS_OPACITY_REFLECTION_W = 1 << 19,
    };

    struct AnimMaterialResult {
        CalcMatAnimResult matAnimCalcResult;
        MaterialColorData materialColorData;
    };

    CalcMatAnimResult CalcMaterialAnimation(const MaterialAnimationResource* resource, float time, MaterialColorData* ret);

    class AnimMaterialControl : public MirageAnimController<int, AnimMaterialResult> {
    public:
        typedef int ID;
        typedef AnimMaterialResult Result;

        int flags;
        intrusive_ptr<MeshResource> mesh;
        intrusive_ptr<MaterialAnimationResource> resource;
        MaterialColorData materialColorData;
        CalcMatAnimResult matAnimCalcResult;
        int idx;

        static AnimMaterialControl* Create(intrusive_ptr<MaterialAnimationResource>& resource);

        virtual bool GetResult(int* idx, AnimMaterialResult* ret) override;
        virtual void Bind(intrusive_ptr<MeshResource>& meshResource, const char* materialName);
        virtual void Bind(intrusive_ptr<MeshResource>& meshResource);
        virtual void Unbind();
    };
}
