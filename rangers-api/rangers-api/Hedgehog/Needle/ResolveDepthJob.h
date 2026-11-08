#pragma once

namespace hh::needle {
    class ResolveDepthJob : public RenderJob {
    public:
        ShaderUtil shaderUtil{};

        inline ResolveDepthJob() {}

        virtual void Start(const RenderJobContext& context) override;
        virtual void Stop() override {}
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int GetClassSize() override;
    };
}
