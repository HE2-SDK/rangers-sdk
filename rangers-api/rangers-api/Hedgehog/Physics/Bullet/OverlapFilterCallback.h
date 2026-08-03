#pragma once

namespace hh::physics::bullet {
    class OverlapFilterCallback : public btOverlapFilterCallback {
    public:
        int* unk0;

        virtual bool needBroadphaseCollision(btBroadphaseProxy* proxy0, btBroadphaseProxy* proxy1) const override;

        OverlapFilterCallback(int* unk0);
    };

    class GhostOverlapFilterCallback : public btOverlapFilterCallback {
    public:
        virtual bool needBroadphaseCollision(btBroadphaseProxy* proxy0, btBroadphaseProxy* proxy1) const override;
    };
}