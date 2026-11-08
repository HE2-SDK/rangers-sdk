#pragma once

namespace hh::needle {
    class DefaultDeferredRenderJob : public DeferredRenderJob {
    public:
        uint64_t unk201;
        uint64_t unk202;

        DefaultDeferredRenderJob(csl::fnd::IAllocator* allocator, unsigned int viewportId);

        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int GetClassSize() override;
        virtual void UnkFunc19(const RenderJobContext& context) override;
        virtual void UnkFunc20(const RenderJobContext& context) override;
        virtual void UnkFunc21(const RenderJobContext& context) override;
        virtual void InitializeModelJobs(RenderingPipeline* pipeline) {}
        virtual void InitializeJobs0(RenderingPipeline* pipeline) {}
        virtual void InitializeJobs1(RenderingPipeline* pipeline);
    };
}
