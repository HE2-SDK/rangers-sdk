#pragma once

namespace hh::physics {
    class GOCCollider;
}

namespace hh::physics::bullet {
    class RigidBody : public Collider {
    public:
        char byte48;
        int64_t qword50;
        int64_t qword58;
        int64_t qword60;
        int64_t qword68;
        csl::ut::MoveArray<int64_t> qword70;
        csl::ut::MoveArray<int64_t> qword90;
        int dwordB0;

        virtual void OnAddedCallback() override;
        virtual void OnRemovedCallback(PhysicsWorldBullet* physicsWorldBullet, game::GameObject& ownerGameObject, void* data) override;
        virtual void* GetRuntimeTypeInfo() const override;
        virtual void SetTransform(fnd::WorldPosition& transform, char stateUpdateType, void* data) override;

        RigidBody(GOCCollider* gocCollider, btRigidBody* rigidBody);
    };
}
