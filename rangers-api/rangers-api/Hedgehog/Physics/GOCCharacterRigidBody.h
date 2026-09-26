#pragma once

namespace hh::physics {
    class CharacterRigidBodyListener : public fnd::ReferencedObject {
    public:
        virtual void CRBL_UnkFunc0(int64_t a2) = 0;
    };

    class GOCCharacterRigidBody : public hh::game::GOComponent {
    public:
        short word80;
        float dword84;
        float dword88;
        float dword8C;
        float dword90;
        float dword94;
        int64_t qword98;
        int64_t qwordA0;
        csl::math::Vector4 owordB0;
        csl::math::Vector4 owordC0;
        GOCCollider* gocCollider;
        fnd::Reference<CharacterRigidBodyListener> listener;
        game::GOCTransform* gocTransform;
        fnd::WorldPosition gocColliderTransform;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void GCRB_UnkFunc0() = 0;
        virtual void GCRB_UnkFunc1() = 0;
        virtual void GCRB_UnkFunc2() = 0;
        virtual void OnColliderSet(GOCCollider* gocCollider) = 0;
        virtual void OnColliderRemoved(GOCCollider* gocCollider) = 0;

        void SetListener(CharacterRigidBodyListener* listener);

        GOCCharacterRigidBody(csl::fnd::IAllocator* allocator);
    };

    class GOCCharacterRigidBodyBullet : public GOCCharacterRigidBody {
    public:
        bullet::CharacterRb* currentCharacterRb;
        bullet::CharacterRb characterRb;

        virtual void GCRB_UnkFunc0() override {}
        virtual void GCRB_UnkFunc1() override {}
        virtual void GCRB_UnkFunc2() override {}
        virtual void OnColliderSet(GOCCollider* gocCollider) override;
        virtual void OnColliderRemoved(GOCCollider* gocCollider) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCCharacterRigidBodyBullet);
    };
}
