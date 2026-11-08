#pragma once

namespace app::physics{
    class GOCMoveSphereColliderQuery;
}

namespace app::player{
    class StatePluginCollision : public PlayerStatePlugin {
    public:
        struct BodyAttackParam {
            unsigned char type;
            csl::math::Vector3 position;
            float radius;
            char unk0;
        };

        struct DamageCollider {
            hh::fnd::Handle<hh::physics::GOCCollider> collider;
            char unk0;
            char unk0b;
            char unk0c;
            int unk1;
            float unk2;
            int flags;
            int unk4;
        };

        struct Unk1 {
            app::ut::PriorityList<BodyAttackParam, unsigned int> bodyAttackParams;
            physics::GOCMoveSphereColliderQuery* colliderQuery;
            unsigned char currentType;
        };

        static constexpr const char* name = "StatePluginCollision";

        csl::ut::MoveArray<DamageCollider> damageColliders;
        Unk1 colliderThings;
        unsigned char unk202;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;

        void SetTypeAndRadius(unsigned char type, float radius);
        void CreateAttackCollision(heur::rfl::PlayerParamAcceleCombo& param, char type, const char* name);
        void DestroyAttackCollision(unsigned int nameHash);
    
        DEFAULT_CREATE_FUNC(StatePluginCollision);
    };
}
