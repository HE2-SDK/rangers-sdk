#pragma once

namespace Cyan::Graphics {
    class CyanModelCreationInfoCreator : public hh::needle::ModelCreationInfoCreator {
    public:
        virtual void SetupMaterialPass(
            const hh::needle::MaterialResource* material, 
            hh::needle::CNameIDObject* a3, 
            const hh::needle::MaterialResourcePassSetupInfo* setupInfo, 
            hh::needle::MaterialResourcePassMeasureInfo* measureInfo) const override;
    };

    class MeshRendererNeedle : public hh::needle::ModelInstanceRenderer {
    public:
        ManagerImpl* manager;
        hh::needle::intrusive_ptr<hh::needle::ParameterValueObject> gammaCorrect;

        virtual void SetupGatherRenderingPassContext(unsigned int idx, hh::needle::GatherRenderingPassContext* ctx) const override;
        virtual void* CreateModel(hh::needle::MeshResource* mesh, hh::needle::RenderingDevice* renderingDevice, const Resource::ModelOption& modelOption) const;
        virtual hh::needle::ParameterValueObject* CreateGlobalparamContainer(unsigned int unk0) const;

        static MeshRendererNeedle* Create(System::IAllocator* allocator);
    };

    class MeshRenderer : public Renderer {
    public:
        MeshRendererNeedle* meshRendererNeedle;

        MeshRenderer(ManagerImpl* managerImpl);

        virtual void Initialize(const DeviceContainer& deviceContainer) override {}
        virtual unsigned int Render(const DeviceContainer& deviceContainer, unsigned int unkParam1, unsigned int unkParam2, unsigned int unkParam3, unsigned int unkParam4, void* unkParam5) override;
        virtual EffectObject* BeginEmitter(const EmitterDecl& emitterDecl) override;
        virtual void UnkFunc5(void* unkParam1) override;
        virtual void AddParticle(Graphics::EffectObject* effectObject, const Graphics::ParticleDecl& particleDecl, const Matrix23* matrices) override;
        virtual void AddCpuTransformedParticle(Graphics::EffectObject* effectObject, const Graphics::ParticleDecl& particleDecl, const Matrix23* matrices) override;
        virtual void UnkFunc9();
    };
}
