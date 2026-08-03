#pragma once

namespace app{
    class PassPlaneListener {
    public:
        virtual void OnEnter(char playedId) = 0;
        virtual void OnLeave(char playedId) = 0;
    };  

    class PassPlaneTrigger : public hh::physics::GOCColliderListener {
    public:
        enum class Flags : unsigned char {
            ENABLED
        };

        enum class State : unsigned int {
            INACTIVE,
            INSIDE,
            LEAVING
        };

        hh::game::GameObject* ownerObject;
        hh::physics::GOCBoxCollider* gocCollider;
        csl::ut::MoveArray<PassPlaneListener*> listeners;
        int64_t qword38;
        heur::rfl::PassPlaneTriggerSpawner passPlaneParams;
        int dword60;
        int64_t qword68;
        int64_t qword70;
        int64_t qword78;
        csl::ut::Bitset<Flags> flags;
        State triggerState;

        virtual void OnStay(hh::physics::MsgTriggerStay& msg) override;
        virtual void OnLeave(hh::physics::MsgTriggerLeave& msg) override;

        void Setup(hh::game::GameObject* gameObject, const heur::rfl::PassPlaneTriggerSpawner& params, int64_t unk0);
        void AddListener(PassPlaneListener* listener);
        void HandleMessage(hh::fnd::Handle<hh::game::GameObject>& actor);
        void Enable(bool enabled);

        PassPlaneTrigger(csl::fnd::IAllocator* allocator);
    };
}
