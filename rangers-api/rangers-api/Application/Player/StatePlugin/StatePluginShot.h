#pragma once

namespace app::player {
    class StatePluginShot : public PlayerStatePlugin {
    public:
        csl::ut::MoveArray<void*> unk28;
        csl::ut::MoveArray<void*> unk48;
        csl::ut::MoveArray<void*> unk68;
        uint32_t byte88;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginShot);
    };
}
