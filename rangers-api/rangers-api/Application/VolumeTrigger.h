#pragma once

namespace app {
    class VolumeListener {
    public:
        virtual void OnEnter(hh::physics::MsgTriggerEnter& msg);
        virtual void OnStay(hh::physics::MsgTriggerStay& msg);
        virtual void OnLeave(hh::physics::MsgTriggerLeave& msg);
    };

    class VolumeTrigger : public hh::physics::GOCColliderListener {
    public:
        hh::game::GameObject* gameObject;
        uint32_t unk2;
        bool detectStay;
        hh::physics::GOCCollider* collider;
        hh::gfx::GOCVisualDebugDraw* debugVisual;
        csl::ut::MoveArray<VolumeListener*> listeners;
    
    protected:
        void Setup(hh::game::GameObject* object, const heur::rfl::VolumeTriggerSpawner& config);

    public:
        // CollisionFilter changes the collider type
        // 0 = category 25, unk4 0x001000 
        // 1 = category 27, unk4 0x010000 
        // 2 = category 29, unk4 0x018000 
        // 3 = category 29, unk4 0x158000 
        heur::rfl::VolumeTriggerSpawner config;
        uint8_t unk13;
    
        DEFAULT_CREATE_FUNC(VolumeTrigger)

        virtual void OnEnter(hh::physics::MsgTriggerEnter& msg) override;
        virtual void OnStay(hh::physics::MsgTriggerStay& msg) override;
        virtual void OnLeave(hh::physics::MsgTriggerLeave& msg) override;

        void Setup(hh::game::GameObject* object, const heur::rfl::VolumeTriggerSpawner& config, uint32_t unkParam1, bool detectStay);
        void SetupDebugVisual();
        void UpdateConfig(const heur::rfl::VolumeTriggerSpawner& config);
        void UpdateDebugVisual(const heur::rfl::VolumeTriggerSpawner& config);
        void AddListener(VolumeListener* listener);
        void RemoveListener(VolumeListener* listener);

        void StartActiveObjectInEditor();
        void UpdateActiveObjectInEditor();
        void FinishActiveObjectInEditor();
    };
}
