#pragma once

namespace hh::needle {
    struct MaterialparamSetting {
        InstanceParameterContainerData** globalParameterSettings;
        void* unk1;
        size_t unk2;
        size_t unk3;
    };

    struct PBRModelCreationInfo {
        Texture** textures;
        int flags;
        int64_t unk0a;
        Texture* textures1[3];
        int unk0; // samplerRelated
        int unk1;
    };
    
    MaterialparamSetting* GetMaterialparamSetting(int index);

    class AnimMaterialControl;
    class AnimTexSrtControl;
    class AnimTexPatControl;
    class AnimVisControl;

    class PBRModelInstance : public ModelInstance {
    public:
        int64_t unk3;
        int64_t unk4;
        AnimBlender<AnimMaterialControl>* matBlender;
        AnimBlender<AnimTexPatControl>* texPatBlender;
        AnimBlender<AnimTexSrtControl>* texSrtBlender;
        AnimBlender<AnimVisControl>* visBlender;
        int64_t unk9;
        int64_t unk10;
        char unk11[0x30];
        char unk12[0x30];
        short unk13;
        bool isVisible;
        int unk15;

        virtual void UnkFunc8() override;
        virtual void UnkFunc9() override;
        virtual void UnkFunc10() override;
        virtual void UnkFunc11() override;
        virtual void UnkFunc12() override;
        virtual void UnkFunc13() override;
        virtual void UnkFunc14() override;
        virtual void UnkFunc15() override;

        void SetShadowReceiveFlag(bool enabled);
        void GetModelSpaceAabb(csl::geom::Aabb* aabb) const;
        static InstanceParameterContainerData* GetGlobalParameterSetting();
        static ParameterValueObject* CreateGlobalParamContainer();
        static PBRModelInstance* Create(Model* model, const PBRModelCreationInfo& info, const PBRModelInstanceRenderer* renderer);
        void SetTexSrtBlender(AnimBlender<AnimTexSrtControl>* blender);
        void SetMaterialBlender(AnimBlender<AnimMaterialControl>* blender);
        void SetTexPatBlender(AnimBlender<AnimTexPatControl>* blender);
        void SetVisibilityBlender(AnimBlender<AnimVisControl>* blender);
        void SetVisible(bool visible);
    };
}
