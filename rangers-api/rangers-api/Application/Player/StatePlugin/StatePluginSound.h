#pragma once

namespace app::player {
    class StatePluginSound : public PlayerStatePlugin {
    public:
        csl::ut::MoveArray<void*> unk201;
        csl::ut::MoveArray<void*> unk202;

        virtual unsigned int GetNameHash() const override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginSound);
    };
}
