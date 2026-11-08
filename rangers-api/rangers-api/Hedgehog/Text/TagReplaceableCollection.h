#pragma once

namespace hh::text {
    class TagReplacer;

    class TagReplaceableCollection : public TagReplaceable {
    public:
        csl::ut::MoveArray<TagReplacer*> replacers;
        
        TagReplaceableCollection(csl::fnd::IAllocator* pAllocator);
    };
}
