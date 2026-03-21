#pragma once

namespace app::player {
    class EffectLocus : public PlayerEffect {
    public:
        uint32_t dword48;

        CREATE_FUNC(EffectLocus, hh::game::GameObject* playerObject, PlayerVisual* playerVisual);

        virtual unsigned int GetNameHash() const override;
    };
}
