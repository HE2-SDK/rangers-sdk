#pragma once

namespace hh::anim {
    class SkeletalMeshBinding;
    class ResSkeleton;
    class Pose;
}

namespace hh::gfx {
    // Actually called GOCVisualMode::Description but I'm not sure how to resolve the mutual dependency with Setup.
    // Assumed, some of these fields may not be part of this but of the GOCVisualModel instead
    struct GOCVisualModelDescription : public GOCVisualTransformed::SetupInfo {
        enum class Flag {
            SCENE_EDITOR_RENDER = 0x14,
            NO_CONTROL_RENDER_OPTION = 0x15,
            RENDER_COLOR_MASK = 0x16,
            NO_SHADOW_RECEIVE = 0x17,
            NO_SHADOW_CAST = 0x18,
            NO_MATERIAL_OPTIMIZE = 0x19,
            UNK1 = 0x1A, // Assigned in GOCVisualModelImpl::Setup
            UNK2 = 0x1B,
            IS_HEIGHTMAP_REACTOR = 0x1C,
            IS_SHADOW_RECEIVE = 0x1D,
            IS_SHADOW_CASTER = 0x1E,
        };
        gfx::ResModel* model;
        uint64_t unk318;
        fnd::ManagedResource* skeleton;
        csl::ut::Bitset<Flag> flags;
        uint32_t unk320;
        int skeletalAnimationRelatedUnk;
        int skeletalAnimationRelatedUnk2;
        uint32_t unk321;
        uint32_t unk322;
        gfnd::ResTexture* giTexture;
        gfnd::ResTexture* giOcclusionTexture;
        fnd::ManagedResource* unk325;
        bool isSky;
        bool isOccluder;
        bool disableColorDraw;
        bool useGIPRT;
        bool useGISG;
        unsigned int name;
        unsigned int masterPoseComponentName; // a GOCVisualModel
        bool unk304;
        bool notUpdateFinal;

        GOCVisualModelDescription();
    };

    struct GOCVisualModelSpawner {
        csl::ut::VariableString resModel;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GOCVisualModelSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GOCVisualModelSpawner* pInstance);
        static void Clean(GOCVisualModelSpawner* pInstance);
    };

    inline const hh::fnd::RflTypeInfo GOCVisualModelSpawner::typeInfo{
        "GOCVisualModelSpawner",
        "GOCVisualModelSpawner",
        [](void* instance, csl::fnd::IAllocator* allocator) {
            auto* inst = static_cast<GOCVisualModelSpawner*>(instance);
            new (&inst->resModel) csl::ut::VariableString{ allocator };
            return instance;
        },
        [](void* instance) {},
        [](void* instance) {
            auto* inst = static_cast<GOCVisualModelSpawner*>(instance);
            inst->resModel.~VariableString();
        },
        sizeof(GOCVisualModelSpawner),
    };

    class GOCVisualModel;
    class GOCVisualModelImpl {
    public:
        struct Unk1 {
            uint8_t unk1;
            uint8_t unk2;
            uint32_t unk3[64];
            uint8_t unk4;
        };

    public:
        needle::PBRModelInstance* modelInstance;
        csl::fnd::IAllocator* allocator;
        uint16_t unk2;
        int rootNode;
        uint32_t unk4;
        uint64_t unk5;
        needle::Model model;
        uint64_t unk6b;
        uint64_t unk6c;
        uint64_t unk6d;
        uint32_t unk7;
        int unk8;
        float scale;
        Unk1 unk10;
        uint64_t unk11;
        uint64_t unkpad[67];

        GOCVisualModelImpl(csl::fnd::IAllocator* allocator);
        uint64_t OnGOCVisualEvent(GOCVisualModel* visualModel, int unkParam1, unsigned int unkParam2, void* unkParam3);
        void Setup(GOCVisualModel& model, const GOCVisualModelDescription& description);
        void GetModelSpaceAabb(csl::geom::Aabb* aabb) const;
        void SetShaderParameterFloat(const char* materialName, const char* shaderParamName, const float* value);

        // TexSrtControl* SetTexSrtAnimation(hh::gfx::TexSrtDesc& description);
        TexSrtBlender* SetTexSrtBlender(hh::gfx::TexSrtBlenderDesc& description);
        // void ResetTexSrtAnimation();

        // TexPatControl* SetTexPatAnimation(hh::gfx::TexPatDesc& description);
        TexPatBlender* SetTexPatBlender(hh::gfx::TexPatBlenderDesc& description);
        // void ResetTexPatAnimation();

        // MatAnimControl* SetMaterialAnimation(hh::gfx::MatAnimDesc& description);
        MatAnimBlender* SetMatAnimBlender(hh::gfx::MatAnimBlenderDesc& description);
        // void ResetMaterialAnimation();

        // VisAnimControl* SetVisibilityAnimation(hh::gfx::VisAnimDesc& description);
        VisAnimBlender* SetVisAnimBlender(hh::gfx::VisAnimBlenderDesc& description);
        // void ResetVisibilityAnimation();
    };

    class GOCVisualModel : public GOCVisualTransformed {
    public:
        enum class AnimFlag : unsigned int {
            HAS_MAT_ANIM_BLENDER,
            HAS_TEX_PAT_BLENDER,
            HAS_TEX_SRT_BLENDER,
            UNK0,
            HAS_VIS_ANIM_BLENDER,
        };
        GOCVisualModelImpl* pImplementation;
        GOCVisualModel* masterPoseComponent;
        csl::ut::InplaceMoveArray<GOCVisualModel*, 3> poseComponents;
        unsigned int masterPoseComponentNameHash;
        fnd::Reference<gfx::ResModel> model;
        fnd::Reference<anim::ResSkeleton> skeleton;
        fnd::Reference<TexSrtBlender> texSrtBlender;
        fnd::Reference<TexPatBlender> texPatBlender;
        fnd::Reference<MatAnimBlender> matAnimBlender;
        fnd::Reference<VisAnimBlender> visAnimBlender;
        uint64_t unk306;
        csl::ut::Bitset<AnimFlag> animFlags;
        uint8_t unk312;
        anim::Pose* pose;
        uint64_t unk314;
        fnd::Reference<anim::SkeletalMeshBinding> skeletalMeshBinding;
        float unk316;
        GOCVisualModelDescription description;
        GOCVisualModelImpl implementation;
        uint64_t unk332;

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void LoadReflection(const LoadReflectionInfo& loadReflectionInfo) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void OnGOCVisualEvent(GOCVisualEvent unkParam1, unsigned int unkParam2, void* unkParam3) override;
        void SetMasterPoseComponent(GOCVisualModel* component);
        int GetNodeIndex(const char* nodeName) const;
        void Setup(const GOCVisualModelDescription& description);
        void SetRootNode(int nodeIndex);
        void SetVisibility(const char* sceneRenderPass, bool visible);
        void SetWorld(needle::World* world);
        void SetPose(anim::Pose* pose);
        void ClearPose(anim::Pose* pose);
        void SetShaderParameterFloat(const char* materialName, const char* shaderParamName, const float* value);
		void ClearAABB();

        // TexSrtControl* SetTexSrtAnimation(hh::gfx::TexSrtDesc& description);
        TexSrtBlender* SetTexSrtBlender(hh::gfx::TexSrtBlenderDesc& description);
        TexSrtBlender* GetTexSrtBlender() const;
        // void ResetTexSrtAnimation();

        // TexPatControl* SetTexPatAnimation(hh::gfx::TexPatDesc& description);
        TexPatBlender* SetTexPatBlender(hh::gfx::TexPatBlenderDesc& description);
        TexPatBlender* GetTexPatBlender() const;
        // void ResetTexPatAnimation();

        // MatAnimControl* SetMaterialAnimation(hh::gfx::MatAnimDesc& description);
        MatAnimBlender* SetMatAnimBlender(hh::gfx::MatAnimBlenderDesc& description);
        MatAnimBlender* GetMatAnimBlender() const;
        // void ResetMaterialAnimation();

        // VisAnimControl* SetVisibilityAnimation(hh::gfx::VisAnimDesc& description);
        VisAnimBlender* SetVisAnimBlender(hh::gfx::VisAnimBlenderDesc& description);
        VisAnimBlender* GetVisAnimBlender() const;
        // void ResetVisibilityAnimation();

        GOCOMPONENT_CLASS_DECLARATION(GOCVisualModel)

    private:
        void SetTexSrtBlender(TexSrtBlender* blender);
        void SetTexPatBlender(TexPatBlender* blender);
        void SetMatAnimBlender(MatAnimBlender* blender);
        void SetVisAnimBlender(VisAnimBlender* blender);
    };
}
