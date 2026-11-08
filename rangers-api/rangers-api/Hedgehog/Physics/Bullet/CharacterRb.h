#pragma once

namespace hh::physics {
    class GOCCharacterRigidBodyBullet;
    class PhysicsWorld;
}

namespace hh::physics::bullet {
    class CharacterRb : public ImplBase {
    public:
        GOCCharacterRigidBodyBullet* gocCharacterRB;
        PhysicsWorld* physicsWorld;
        RigidBody rigidBody;
        int64_t qwordD0;

        virtual void OnAddedCallback() override {}
        virtual void OnRemovedCallback(PhysicsWorldBullet* physicsWorldBullet, game::GameObject& ownerGameObject, void* data) override {}
        virtual void* GetRuntimeTypeInfo() const override;

        CharacterRb(GOCCharacterRigidBodyBullet* gocCharacterRBBt, GOCCollider* gocCollider);
    };
}
