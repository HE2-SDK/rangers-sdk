#pragma once

namespace app::player {
    class StateParameter {
        uint32_t unk1;
    public:
        StateParameter(uint32_t unk1Param);

        virtual ~StateParameter() = default;
        virtual StateParameter* Clone(csl::fnd::IAllocator* allocator) const = 0;
        virtual unsigned int GetNameHash() const = 0;
        virtual void Clear() {}
    };
}
