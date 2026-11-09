#pragma once

namespace hh::needle {
    class ImpostorCaptureRenderingPipeline : public CaptureRenderingPipeline {
    public:
        ImpostorCaptureRenderingPipeline(csl::fnd::IAllocator* allocator, PBRModelInstanceRenderer* modelRenderer);

        virtual void InitializeJobs() override;
    };
}
