#pragma once

namespace app::player {
    class EffectHoming : public PlayerEffect {
    public:
        uint8_t dword48;

        CREATE_FUNC(EffectHoming, hh::game::GameObject* playerObject, PlayerVisual* playerVisual);

        virtual unsigned int GetNameHash() const override;
        virtual void UnkFunc3() override;
        virtual void UnkFunc4() override;
    };
}
