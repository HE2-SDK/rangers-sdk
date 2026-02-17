#pragma once

namespace app::player {
    class StatePluginThroughOneway : public PlayerStatePlugin, public PostureListener {
    public:
        uint8_t byte28;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
        virtual void PL_UnkFunc2() override;

        DEFAULT_CREATE_FUNC(StatePluginThroughOneway);
    };
}
