#pragma once

namespace app::player {
    class StatePluginWallJump : public PlayerStatePlugin {
    public:
        csl::math::Vector4 vec30;
        uint32_t unk40;
        uint16_t unk44;
        uint8_t unk46;

        virtual unsigned int GetNameHash() const override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginWallJump);
    };
}
