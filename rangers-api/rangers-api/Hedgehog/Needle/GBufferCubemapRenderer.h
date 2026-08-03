#pragma once

namespace hh::needle {
    class GBufferCubemapRenderer : public RenderJob {
    public:
        int dword48;
        int dword4C;
        char gap50[56];
        intrusive_ptr<Texture> qword88;
        intrusive_ptr<UnorderedAccessView> qword90;
        intrusive_ptr<ShaderObject> liteDeferredShader0;
        intrusive_ptr<ParameterValueObject> liteDeferredShaderParams0;
        intrusive_ptr<ShaderObject> liteDeferredShader1;
        intrusive_ptr<ParameterValueObject> liteDeferredShaderParams1;
        intrusive_ptr<UnorderedAccessView> qwordB8;
        intrusive_ptr<Texture> qwordC0;
        intrusive_ptr<UnorderedAccessView> qwordC8;
        intrusive_ptr<Texture> qwordD0;
        int64_t qwordD8;
        int64_t qwordE0;
        int64_t qwordE8;
        int64_t qwordF0;
        int64_t qwordF8;
        csl::fnd::IAllocator* qword100;
        int64_t qword108;
        int64_t qword110;
        intrusive_ptr<Texture> qword118;
        int64_t qword120;
        intrusive_ptr<Texture> qword128;
        int64_t qword130;
        intrusive_ptr<Texture> qword138;
        int dword140;
        int dword144;

        GBufferCubemapRenderer(csl::fnd::IAllocator* allocator, int a3, int a4);

        virtual void Start(const RenderJobContext& context) override;
        virtual void Stop() override;
        virtual void UnkFunc9(PipelineInfo* pipelineInfo) override;
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int GetClassSize() override;
    };
}
