#pragma once

namespace hh::needle {
    class FXAAJob : public PostEffectRenderJob {
    public:
        intrusive_ptr<PostEffectShader> shaders[3];
        int fxaaQuality;

        FXAAJob(RenderManager* renderManager);

        virtual void UnkFunc9(PipelineInfo* pipelineInfo) override;
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int GetClassSize() override;
        virtual void Setup(const RenderJobContext& context) override;
        virtual void UnkFunc23() override;
    };
}
