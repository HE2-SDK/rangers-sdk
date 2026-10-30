#pragma once

namespace hh::physics{
    class PhysicsOverlapJob : public PhysicsQueryJob {
    public:
        csl::ut::InplaceMoveArray<PhysicsOverlapResult, 1> results; 
        int64_t qwordE0;
        PhysicsOverlapResult otherResults[2];

        PhysicsOverlapJob(csl::fnd::IAllocator* allocator);
    };
}
