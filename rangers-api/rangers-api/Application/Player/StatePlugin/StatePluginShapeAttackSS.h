#pragma once

namespace app::player {
    class StatePluginShapeAttackSS : public PlayerStatePlugin {
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
        virtual bool ProcessMessage(hh::fnd::Message& message) override;

        DEFAULT_CREATE_FUNC(StatePluginShapeAttackSS);
    };
}
