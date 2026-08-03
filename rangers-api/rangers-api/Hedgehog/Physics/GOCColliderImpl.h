#pragma once

namespace hh::physics {
    class GOCColliderImpl {
    public:
        enum class StateUpdateType : unsigned long long {
            ENABLED,
            TRANSFORM,
            SHAPE_CHANGE,
            OBJECT_LAYER = 4,
            FRICTION,
            RESTITUTION,
            SCALE
        };

        virtual ~GOCColliderImpl();
        virtual void OnAdded(GOCCollider* gocCollider) = 0;
        virtual void OnRemoved(GOCCollider* gocCollider) = 0;
        virtual void OnStateUpdate(GOCCollider* gocCollider, StateUpdateType type, void* data) = 0;
        virtual void UnkFunc3() = 0;
        virtual char UnkFunc4() { return false; }
        virtual char UnkFunc5() { return false; }
        virtual void UnkFunc6() = 0;
        virtual void UnkFunc7() = 0;
        virtual void UnkFunc8() = 0;
        virtual void UnkFunc9() = 0;
    };

    struct GOCColliderImplInfo {
		typedef GOCColliderImpl* CreateFunction();

        CreateFunction* constructor;
        size_t objectSize;

        // Unsure whether it should be here, if it's a singular info struct which can be changed easily to swap out the physics engines
        static GOCColliderImplInfo info;
        static GOCColliderImplInfo* GetInfo();
    };

    class GOCColliderBullet : public GOCColliderImpl {
    public:
        bullet::Trigger* collider;
        bullet::Trigger trigger;
        char byteF0;
        fnd::Reference<bullet::CollisionShape> collisionShape;

        virtual void OnAdded(GOCCollider* gocCollider) override;
        virtual void OnRemoved(GOCCollider* gocCollider) override;
        virtual void OnStateUpdate(GOCCollider* gocCollider, StateUpdateType type, void* data) override;
        virtual void UnkFunc3() override;
        virtual char UnkFunc4() override;
        virtual char UnkFunc5() override;
        virtual void UnkFunc6() override;
        virtual void UnkFunc7() override;
        virtual void UnkFunc8() override;
        virtual void UnkFunc9() override;

        GOCColliderBullet();
    };
}
