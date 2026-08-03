#pragma once

namespace hh::needle{
    class SimpleCaptureJob : public RenderJob {
    public:
        int viewportId;
        int renderTargetIndex;
        int64_t qword50;

        SimpleCaptureJob(int viewportId, int renderTargetIndex);

        virtual void Start(const RenderJobContext& context) override;
        virtual void Stop() override {}
        virtual void UnkFunc9(PipelineInfo* pipelineInfo) override {}
        virtual void Render(PipelineInfo* pipelineInfo) override;
    };

    class SimpleCaptureParamBuildJob : public ParamBuildJob {
    public:
        SimpleCaptureJob* captureJob;
        int dword58;
        int viewportId;

        inline SimpleCaptureParamBuildJob() {}

        virtual const char* GetName() = 0;
        virtual unsigned int GetNameHash() = 0;
        virtual unsigned int GetClassSize() = 0;
    };

    class FrameBufferCaptureJob : public SimpleCaptureJob {
    public:
        int dword58;

        FrameBufferCaptureJob(int dword58);

        virtual void Start(const RenderJobContext& context) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int GetClassSize() override;
    };

    class FrameBufferCaptureParamBuildJob : public SimpleCaptureParamBuildJob {
    public:
        inline FrameBufferCaptureParamBuildJob() {}

        virtual void Prepare(ParameterValueObject* parameters, PipelineInfo* pipelineInfo) override {}
        virtual void Run(ParamValueOverrideHelper* paramOverrides, PipelineInfo* pipelineInfo, unsigned int viewportId, unsigned int parameterId) override;
        virtual const char* GetName() override;
        virtual unsigned int GetNameHash() override;
        virtual unsigned int GetClassSize() override;
    };
}

