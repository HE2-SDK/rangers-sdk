#pragma once

namespace hh::physics::bullet {
    class Cache : public WorldObject {
    public:
        btSphereShape* btShape;
        GhostOverlapFilterCallback bulletCallback;

        virtual void OnAddedCallback() override;
        virtual void OnRemovedCallback(PhysicsWorldBullet* physicsWorldBullet, game::GameObject& ownerGameObject, void* data) override;
        virtual void* GetRuntimeTypeInfo() const override;

        void CreateBulletShape();

        Cache(GOCCollider* gocCollider);
    };
}
