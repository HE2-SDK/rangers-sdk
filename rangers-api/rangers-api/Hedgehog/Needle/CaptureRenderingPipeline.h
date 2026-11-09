#pragma once

namespace hh::needle{
    class CaptureRenderingPipeline : public WorldRenderingPipeline {
    public:
        const char* name;

        inline CaptureRenderingPipeline(csl::fnd::IAllocator* allocator) : WorldRenderingPipeline{ allocator } {}
    };
}
