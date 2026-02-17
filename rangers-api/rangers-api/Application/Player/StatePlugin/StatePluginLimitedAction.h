#pragma once

namespace app::player {
    class StatePluginLimitedAction : public PlayerStatePlugin {
    public:
        uint32_t unk201;

        virtual unsigned int GetNameHash() const override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginLimitedAction);
    };
}
