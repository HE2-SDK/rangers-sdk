#pragma once

namespace hh::physics {
    class PhysicsWorldBullet;
}

namespace hh::physics::bullet {
    class WorldObject : public ImplBase {
    public:
        GOCCollider* gocCollider;
        PhysicsWorldBullet* physicsWorldBullet;
        bool isEnabled;
        csl::ut::InplaceMoveArray<btCollisionObject*, 1> objects;

        virtual void OnAddedCallback() override;
        virtual void OnRemovedCallback(PhysicsWorldBullet* physicsWorldBullet, game::GameObject& ownerGameObject, void* data) override;
        virtual void* GetRuntimeTypeInfo() const override;
        virtual ~WorldObject();

        void AddObject(btCollisionObject* object);

        WorldObject(GOCCollider* gocCollider, bool isEnabled);
    };
}
