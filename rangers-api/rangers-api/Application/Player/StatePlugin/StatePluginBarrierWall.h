#pragma once

namespace app::player {
    class StatePluginBarrierWall : public PlayerStatePlugin {
    public:
        hh::eff::EffectHandle unk28;
        uint64_t unk38;
        uint32_t unk40;
        uint8_t unk44;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginBarrierWall);
    };
}
