#pragma once

namespace app::trr {
    class TerrainVisualObject : public hh::game::GameObject {
    public:
        struct Sector {
            struct LightInstance {
                hh::fnd::ResLightParameter lightParameter;
                hh::fnd::Reference<hh::gfx::ResAnimLightContainer> lightAnimationResource;
                hh::fnd::HFrame* hFrame;
                float loadingRange;
                bool animationOn;
                const char* instanceName;
                int idx;

                void Initialize(hh::gfx::ResMirageLight* light, ucsl::resources::pointcloud::v2::InstanceData& instanceData, hh::gfx::ResAnimLightContainer* lightAnim, hh::fnd::HFrame* hFrame, bool unk1);
                void SetGOCPointLight(hh::gfx::GOCPointLight* gocPointlight, bool enabled);
                static int CreateLight(hh::gfx::GOCPointLight* gocPointLight, LightInstance& lightInstance, hh::fnd::HFrame* hFrame, const char* instanceName);
            };

            struct PCModelInstance {
                const char* name;
                csl::ut::MoveArray<csl::geom::Aabb> aabbs; //unsure
                hh::gfx::GOCVisualModel* goc;
                char unk1;
            };

            csl::ut::MoveArray<hh::gfx::GOCVisualModel*> models;
            csl::ut::MoveArray<PCModelInstance> pcModelInstances;
            csl::ut::MoveArray<LightInstance> lightInstances;
            uint32_t unk4; //handles?
            uint32_t unk5; //handles?
            bool enabled;
        };

        TerrainWorld* world;
        hh::game::GOCTransform* gocTransform;
        hh::gfx::GOCPointLight* gocPointLight;
        csl::ut::MoveArray<Sector> sectors;
        uint8_t unk204;
        bool isNonZeroStageIndex;

        TerrainVisualObject(csl::fnd::IAllocator* allocator);

		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
        virtual void LoadLight(const char* stageId) = 0;
        virtual void UnkFunc13() = 0;
        virtual bool UnkFunc14() = 0;
        virtual void UnkFunc15() {}

        void CreateSector(unsigned int sectorId);

        struct SetupInfo {
            TerrainWorld* world;
            TerrainVisualResourceBinder* resourceBinder;
        };

        void Setup(const SetupInfo& setupInfo);
    };
}
