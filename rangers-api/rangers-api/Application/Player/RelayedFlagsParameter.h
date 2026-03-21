#pragma once

namespace app::player {
    class RelayedFlagsParameter : public StateParameter {
        uint32_t unk101;
    public:
        RelayedFlagsParameter();
        virtual RelayedFlagsParameter* Clone(csl::fnd::IAllocator* allocator) const override;
        virtual unsigned int GetNameHash() const override;
        virtual void Clear() override;
    };
}
