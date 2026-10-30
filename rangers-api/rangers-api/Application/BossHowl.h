#pragma once

namespace app {
    class BossHowl : public hh::game::GameObject {
    public:
        struct Description {
            hh::fnd::Handle<hh::game::GameObject> bossObject;
            hh::fnd::HFrame* sphereFrame;
            float sphereRadius;
            float dword28C;
        };

        int dword248;
        float aliveTimer;
        hh::fnd::Reference<physics::ColliderContainer> colliderContainer;
        csl::ut::MoveArray<int64_t> qword258;
        Description desc;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        void Setup(const Description& desc);
        void HandleTriggerEnter(hh::physics::MsgTriggerEnter& msg);

        GAMEOBJECT_CLASS_DECLARATION(BossHowl);
    };
}
