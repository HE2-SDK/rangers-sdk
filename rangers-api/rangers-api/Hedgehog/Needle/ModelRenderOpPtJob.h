#pragma once

namespace hh::needle{
    class ModelRenderOpPtJob : public ModelRenderJobBase {
    public:
        RenderJobCallback onBeforeRender;
        RenderJobCallback onAfterRender;
        bool useSetRenderTargetsSetting;
        hh::needle::RenderTargetsSetting renderTargetsSetting;
        float width;
        float height;
        bool byte24c;

        ModelRenderOpPtJob(unsigned int viewportId);
        virtual unsigned int UnkFunc6(PipelineInfo* pipelineInfo) override;
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int GetClassSize() override;
    };
}
