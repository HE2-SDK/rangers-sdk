#pragma once

namespace app::player {
    class StatePluginCheckExternalInput : public PlayerStatePlugin {
    public:
        uint8_t flags;

        virtual unsigned int GetNameHash() const override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginCheckExternalInput);
    };
}
