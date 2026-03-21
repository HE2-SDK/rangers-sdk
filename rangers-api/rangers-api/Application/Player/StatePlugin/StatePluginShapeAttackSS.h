#pragma once

namespace app::player {
    class StatePluginShapeAttackSS : public PlayerStatePlugin {
    public:
        uint8_t byte8C;

        virtual unsigned int GetNameHash() const override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;

        DEFAULT_CREATE_FUNC(StatePluginShapeAttackSS);
    };
}
