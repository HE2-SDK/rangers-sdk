#pragma once

namespace app::player {
    class StatePluginDebug : public PlayerStatePlugin {
    public:
        GOCPlayerKinematicParams::Unk5 unk201;
        uint16_t unk202;
        float unk203;
        uint32_t unk204;
        uint32_t unk205;

        virtual unsigned int GetNameHash() const override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginDebug);
    };
}
