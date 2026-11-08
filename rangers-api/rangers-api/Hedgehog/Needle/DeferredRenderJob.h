#pragma once

namespace hh::needle {
    class DeferredShadingJob;

    class DeferredRenderJob : public RenderJob {
    public:
        struct UnkStr {
            int renderLayer012_unk1a{};
            int renderLayer0_unk1{};
            int renderLayer1_unk1{};
            int renderLayer0_drawPassIndex{};
            int renderLayer1_drawPassIndex{};
            CNameIDObject* renderLayer0_name{};
            CNameIDObject* renderLayer1_name{};
            uint32_t renderLayer02_unk2{};
            uint32_t viewportId1{};
            int renderLayer0_unk2a{};
            int renderLayer1_unk2a{};
            RenderJobCallback::Function* onDeferredBeforeRender{};
            RenderJobCallback::Function* onDeferredAfterRender{};
            int renderLayer2_unk1{};
            int renderLayer2_drawPassIndex{};
            CNameIDObject* renderLayer2_name{};
            int renderLayer2_unk2a{};
            int renderLayer0b_unk1a{};
            int renderLayer0b_unk1{};
            int renderLayer0b_drawPassIndex{};
            CNameIDObject* renderLayer0b_name{};
            uint32_t renderLayer0b_unk2a{};
            uint8_t byteDC{};
            uint64_t qwordE0{};
            uint32_t dwordE8{};
            uint64_t qwordF0{};
            uint64_t qwordF8{};
            uint64_t qword100{};
            uint64_t qword108{};
        };

        uint32_t viewportId0;
        RenderingPipeline* deferredRenderingPipeline;
        GatherDrawPassInfoJob* gatherDrawPassJob;
        ParamBuildJob* paramBuildJob;
        UnkStr unkStr68;
        uint64_t enabledBitsCopy;
        DeferredShadingJob* shadingJob;
        void (*getRenderResolutionOverride)(void* userData, float& renderResX, float& renderResY);
        void* getRenderResolutionOverrideUserData;
        void* WorldRenderingPipelineSettings;

        DeferredRenderJob(csl::fnd::IAllocator* allocator, unsigned int viewportId);

        virtual unsigned int UnkFunc6(PipelineInfo* pipelineInfo) override;
        virtual void Start(const RenderJobContext& context) override;
        virtual void Stop() override;
        virtual void UnkFunc9(PipelineInfo* pipelineInfo) override;
        virtual void Render(PipelineInfo* pipelineInfo) override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;
        virtual unsigned int GetClassSize() override;
        virtual unsigned int UnkFunc17() override;
        virtual void UnkFunc19(const RenderJobContext& context) {}
        virtual void UnkFunc20(const RenderJobContext& context) {}
        virtual void UnkFunc21(const RenderJobContext& context) {}
        virtual void SetupDeferredRenderingPipeline(const RenderJobContext& context);
    };
}
