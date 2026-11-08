#pragma once

namespace hh::needle{
    class CopyColorJob : public PostEffectRenderJob{
    public:
        PostEffectShader* postEffectShader;

        CopyColorJob();

        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int GetClassSize() override;
        virtual void Setup(const RenderJobContext& context) override;
    };
}
