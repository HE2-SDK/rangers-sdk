#pragma once

namespace app::player {
    class RunningStartParameter : public StateParameter {
    public:
        float speed;
        float time;

        RunningStartParameter();

        virtual RunningStartParameter* Clone(csl::fnd::IAllocator* allocator) const override;
        virtual unsigned int GetNameHash() const override;
    };
}
