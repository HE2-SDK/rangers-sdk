#pragma once

namespace hh::dv{
    class DvNodeStage : public DvNodeBase{
    public:
        struct Description : DvNodeBase::Description {
            int unk0;
            char stageName[136];
            int unk3;
            int unk4;
        };

        Description binaryData;

        virtual void Setup(DvNodeBase::Description& description) override;
        virtual void Start() override;

        DV_NODE_DECLARATION_BASE(DvNodeStage)
    };
}
