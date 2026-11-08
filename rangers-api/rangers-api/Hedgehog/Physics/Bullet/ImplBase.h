#pragma once

namespace hh::physics {
    class PhysicsWorldBullet;
}

namespace hh::physics::bullet {
    class ImplBase {
    public:
        virtual void OnAddedCallback() = 0;
        virtual void OnRemovedCallback(PhysicsWorldBullet* physicsWorldBullet, game::GameObject& ownerGameObject, void* data) = 0;
        virtual void* GetRuntimeTypeInfo() const = 0;
    };
}
