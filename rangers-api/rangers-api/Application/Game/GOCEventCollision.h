#pragma once

namespace app::game {
    class GOCEventCollision : public GOCEvent {
    public:
        enum class Condition : uint8_t {
            ON_TRIGGER = 0,
            ON_STAY = 1,
            PULSE = 3,
        };

    private:
        class CollisionListener : public hh::physics::GOCColliderListener {
        public:
            GOCEventCollision* gocEventCollision;
            uint32_t unk2;
            uint32_t unk3;
            Condition condition;

            virtual void OnEnter(hh::physics::MsgTriggerEnter& msg) override;
            virtual void OnLeave(hh::physics::MsgTriggerLeave& msg) override;
            virtual void OnStay(hh::physics::MsgTriggerStay& msg) override;
        };

    public:
        CollisionListener collisionListener;
        float lifetime;
        float timeLeft;
        bool lifetimeReached;
        uint64_t unk204; // some kind of filter delegate


        struct SetupInfo : public GOCEvent::SetupInfo {
            Condition condition;
            uint32_t unk102;
            float lifetime;

            SetupInfo();
        };

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void OnGOCEvent(hh::game::GOComponent::GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& setupInfo);
        void UpdateConfig();

        GOCOMPONENT_CLASS_DECLARATION(GOCEventCollision)
    };
}
