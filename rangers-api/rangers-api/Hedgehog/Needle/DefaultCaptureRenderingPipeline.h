#pragma once

namespace hh::needle {
    class DefaultCaptureRenderingPipeline : public CaptureRenderingPipeline {
    public:
        DefaultCaptureRenderingPipeline(csl::fnd::IAllocator* allocator, PBRModelInstanceRenderer* modelRenderer);

        virtual void InitializeJobs() override;
    };
}
