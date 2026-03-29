#pragma once

namespace app::player {
    class EffectLookAt : public PlayerEffect {
    public:
        uint64_t unk201;

        CREATE_FUNC(EffectLookAt, hh::game::GameObject* playerObject, PlayerVisual* playerVisual);

        virtual unsigned int GetNameHash() const override;
    };
}
