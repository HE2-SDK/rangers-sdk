#pragma once

namespace app::player {
    class StatePluginPushBox : public PlayerStatePlugin {
    public:
        csl::math::Vector4 vec30;
        uint64_t unk40;
        uint8_t unk48;
        uint32_t unk4C;

        virtual unsigned int GetNameHash() const override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginPushBox);
    };
}
