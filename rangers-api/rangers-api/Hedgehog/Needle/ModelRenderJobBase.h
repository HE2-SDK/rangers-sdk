#pragma once

namespace hh::needle {
    class ModelRenderJobBase : public RenderJob {
    public:
        struct RenderLayer {
            int32_t unk1;
            int32_t unk1a;
            int32_t unk2; // used for GatherDrawPassInfoJob::AddUnk2
            int32_t unk2a; // related to priority?
            CNameIDObject* name;
            uint32_t unk4; // related to priority?
            int drawPassIndex; // unsure. used for GatherDrawPassInfoJob::AddUnk1
        };

        uint32_t unk101;
        unsigned int viewportId;
        RenderLayer renderLayers[12];

        ModelRenderJobBase(unsigned int viewportId);
        virtual void Start(const RenderJobContext& context) override {}
        virtual void Stop() override {}
        virtual void SetRenderLayer(unsigned int index, const RenderLayer& renderLayer);
    };
}
