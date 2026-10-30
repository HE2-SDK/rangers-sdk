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

        virtual void Initialize(const DeviceContainer& deviceContainer) {}
        virtual unsigned int Render(const DeviceContainer& deviceContainer, unsigned int unkParam1, unsigned int unkParam2, unsigned int unkParam3, unsigned int unkParam4, void* unkParam5);
        virtual void* UnkFunc4(void* unkParam1);
        virtual void UnkFunc5(void* unkParam1);
        virtual void UnkFunc6(void* unkParam1, void* unkParam2, void* unkParam3);
        virtual void UnkFunc7(void* unkParam1, void* unkParam2, void* unkParam3);
        virtual void UnkFunc9();
    };
}
