#pragma once

namespace app::player {
    class StatePluginCameraTarget : public PlayerStatePlugin {
    public:
        uint16_t word28;
        csl::math::Vector4 csl__math__vector430;
        csl::math::Vector4 csl__math__vector440;
        csl::math::Vector4 csl__math__vector450;
        uint8_t gap60[32];
        uint8_t byte80;
        app::Timer timer84;
        uint8_t byte8C;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginCameraTarget);
    };
}
