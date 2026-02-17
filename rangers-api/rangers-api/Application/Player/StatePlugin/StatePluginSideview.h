#pragma once

namespace app::player {
    class StatePluginSideview : public PlayerStatePlugin {
    public:
        uint8_t byte28;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginSideview);
    };
}
