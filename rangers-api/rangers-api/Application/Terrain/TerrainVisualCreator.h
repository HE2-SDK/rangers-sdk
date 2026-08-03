#pragma once

namespace app::trr {
    class TerrainVisualCreator : public hh::fnd::ReferencedObject {
    public:
        struct State {
            class Idle : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateModelInstance : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateTerrainModelInstance : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                csl::ut::MoveArray<void*> resources;
                unsigned int currentResourceIndex;

                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreatePointcloudModelInstance : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                csl::ut::MoveArray<gfx::ResPointcloudModel*> resources;
                unsigned int currentResourceIndex;

                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateGrassModelInstance : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateTerrainModel : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateModel : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateTerrainDensityInstance : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateTerrainDensityPointcloud : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                csl::ut::MoveArray<hh::gfx::ResDensityPointCloud*> resources;
                int currentResource;

                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class InitTerrainDensityCollision : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateTerrainDensityCollision : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class EndUpdateTerrainDensity : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class Finish : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };
        };

        typedef void UnkCB(hh::game::GameObject* gameObject, void* unkParam1);

        TerrainVisualObject* object;
        hh::ut::HsmBase hsm;
        hh::fnd::Reference<hh::ut::StateManager> stateManager;
        TerrainVisualResourceBinder* resourceBinder;
        UnkCB* cb1;
        hh::gfnd::ResTexture* noGITexture;
        hh::gfnd::ResTexture* noGIOcclusionTexture;
        uint64_t qwordB8;
        uint64_t qwordC0;
        csl::ut::String* currentLoading0; //uses as a buffer to set what level it's loading at the moment
        uint64_t qwordD0;
        uint64_t qwordD8;
        csl::ut::String* currentLoading1; //uses as a buffer to set what level it's loading at the moment
        uint64_t qwordE8;
        csl::fnd::IAllocator* qwordF0;

        void StepHSM(float deltaTime);

        struct ModelInstanceDescription {
            hh::fnd::ManagedResource* resource;
            const char* idname;
            csl::math::Matrix34 worldTransform;
            const char* resourceName;
            const char* instanceName;
            int64_t unk1;
            int64_t unk2;
            int64_t unk3;
        };

        void CreateModelInstance(const ModelInstanceDescription& desc);

        CREATE_FUNC(TerrainVisualCreator, TerrainVisualObject* object, TerrainVisualResourceBinder* resourceBinder, UnkCB* cb1Param);
    };
}
