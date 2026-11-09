#pragma once

namespace hh::needle {
    class BlendModelCaptureRenderingPipeline : public CaptureRenderingPipeline {
    public:
        BlendModelCaptureRenderingPipeline(csl::fnd::IAllocator* allocator, PBRModelInstanceRenderer* modelRenderer);

        virtual void InitializeJobs() override;
    };
}
