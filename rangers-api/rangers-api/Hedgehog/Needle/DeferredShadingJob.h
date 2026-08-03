#pragma once

namespace hh::needle {
    class DeferredShadingJob : public PostEffectRenderJob {
    public:
        ShaderUtil liteDeferredPS0;
        ShaderUtil deferredPS;
        ShaderUtil tiledDeferredRenderingCS;
        ShaderUtil liteDeferredPS1;
        ShaderUtil liteDeferredPS2;
        unsigned int viewportId;
        int dword16C;
        intrusive_ptr<UnorderedAccessView> uavs[2];
        void* qword180;
        int64_t qword188;
        intrusive_ptr<RenderJob> ambientRenderJob;

        DeferredShadingJob(unsigned int viewportId, int a3);

        virtual void UnkFunc9(PipelineInfo* pipelineInfo) override;
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int GetClassSize() override;
        virtual void Setup(const RenderJobContext& context) override;
        virtual void UnkFunc23() override;
    };
}
