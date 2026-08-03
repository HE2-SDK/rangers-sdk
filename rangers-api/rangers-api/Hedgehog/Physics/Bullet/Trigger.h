#pragma once

namespace hh::physics::bullet {
    class Trigger : public Collider, public CollisionObjectListener {
    public:
        int64_t qword50;
        int64_t qword58;
        char word60;
        char objectLayer;
        GhostOverlapFilterCallback overlapFilterCallback;
        csl::ut::InplaceMoveArray<int64_t, 10> qword70;

        virtual void Init() override;
        virtual void UnkFunc1(int64_t a2) override;
        virtual void* GetRuntimeTypeInfo() const override;
        virtual void SetTransform(fnd::WorldPosition& transform, char stateUpdateType, void* data) override;
        virtual void SetObjectLayer(char objectLayer, void* unk, void* data) override;

        virtual void COL_UnkFunc0() override;
        virtual int64_t COL_UnkFunc1(int64_t a2) override;

        Trigger(GOCCollider* gocCollider, CollisionShape* collisionShape, bool isEnabled);
    };
}
