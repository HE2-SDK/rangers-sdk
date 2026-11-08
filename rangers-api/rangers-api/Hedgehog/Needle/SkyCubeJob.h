#pragma once

namespace hh::needle {
    class SkyCubeJob : public RenderJob {
    public:
        ShaderUtil qword48;
        int64_t qword60;
        intrusive_ptr<SkyProbe> skyProbe;
        IBLGGXSamplingTexture qword70;

        virtual void Start(const RenderJobContext& context) override;
        virtual void Stop() override;
        virtual void UnkFunc9(PipelineInfo* pipelineInfo) override;
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int GetClassSize() override;

        SkyCubeJob();
    };
}
