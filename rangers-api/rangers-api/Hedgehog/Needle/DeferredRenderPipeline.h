#pragma once

namespace hh::needle {
    class DeferredRenderPipeline : public RenderingPipeline {
    public:
        DeferredRenderPipeline(csl::fnd::IAllocator* allocator);
    };
}
