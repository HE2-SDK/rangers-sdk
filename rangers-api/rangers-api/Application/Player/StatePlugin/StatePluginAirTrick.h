#pragma once

namespace app::player {
    class StatePluginAirTrick : public PlayerStatePlugin {
    public:
        uint32_t unk201;
        uint32_t unk202;
        uint32_t unk203;
        int unk204;
        uint32_t unk205;
        uint16_t unk206;
        uint8_t unk207;

        virtual unsigned int GetNameHash() const override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginAirTrick);
    };
}
