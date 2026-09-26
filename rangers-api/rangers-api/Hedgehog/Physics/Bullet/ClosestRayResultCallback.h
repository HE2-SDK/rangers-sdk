#pragma once

namespace hh::physics::bullet {
    class ClosestRayResultCallback : public btCollisionWorld::ClosestRayResultCallback {
    public:
        int64_t qword70;
        uint32_t filterMask;
        uint32_t dword7C;
        uint32_t dword80;
        uint32_t dword84;

        ClosestRayResultCallback(csl::math::Vector3& rayFromWorld, csl::math::Vector3& rayToWorld, int64_t a4, uint32_t filterMask);

        virtual bool needsCollision(btBroadphaseProxy* proxy0) const override;
        virtual btScalar addSingleResult(btCollisionWorld::LocalRayResult& rayResult, bool normalInWorldSpace) override;
    };
}
