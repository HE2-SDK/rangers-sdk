#pragma once

namespace hh::dv{
    class DvNodeCameraMotion : public DvNodeBase {
    public:
        struct Description : DvNodeBase::Description {
        public:
            enum class Flags : unsigned int {
                UNK0,
                USE_NEAR_FAR_CLIP
            };

            csl::ut::Bitset<Flags> flags;
            int start;
            int end;
            int field0c;
        };

        Description binaryData;
        csl::ut::MoveArray<needle::intrusive_ptr<needle::AnimCameraControl>> cameras;
        int unk3;
        bool cameraEnabled;

        virtual void Setup(DvNodeBase::Description& description) override;
        virtual void Start() override;
        virtual void Update(int currentFrame) override;
        virtual int GetUpdateTiming() override;

        DV_NODE_DECLARATION_BASE(DvNodeCameraMotion)
    };
}
