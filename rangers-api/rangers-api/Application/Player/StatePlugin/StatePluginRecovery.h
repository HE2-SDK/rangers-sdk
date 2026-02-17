#pragma once

namespace app::player {
    class StatePluginRecovery : public PlayerStatePlugin {
    public:
        void* qword28;
        void* qword30;
        void* qword38;
        void* qword40;
        uint64_t qword48;
        uint64_t qword50;
        csl::ut::MoveArray<void*> unk58;
        uint8_t byte78;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginRecovery);
    };
}
