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

        virtual void Init() override;
        virtual void UnkFunc1(int64_t a2) override;
        virtual void* GetRuntimeTypeInfo() const override;

        WorldObject(GOCCollider* gocCollider, bool isEnabled);
    };
}
