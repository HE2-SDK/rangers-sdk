#pragma once

namespace app::fnd{
    class HFrameContainer : public hh::fnd::ReferencedObject {
    public:
        struct Element {
            hh::fnd::Reference<hh::fnd::HFrame> hFrame;
            unsigned int nameHash;
        };

        csl::ut::MoveArray<Element> hFrames;

        HFrameContainer(csl::fnd::IAllocator* allocator);
        void GetHFramesByHash(unsigned int& nameHash, csl::ut::MoveArray<hh::fnd::HFrame*>& out);
    };
};
