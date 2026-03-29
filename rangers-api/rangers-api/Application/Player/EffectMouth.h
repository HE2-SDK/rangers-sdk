#pragma once

namespace app::player {
    class EffectMouth : public PlayerEffect, public game::PhotoModeListener {
    public:
        uint32_t dword50;
        int dword54;
        uint8_t byte58;
        uint8_t byte59;
        uint64_t qword60;

        CREATE_FUNC(EffectMouth, hh::game::GameObject* playerObject, PlayerVisual* playerVisual, unsigned char unkParam);

        virtual unsigned int GetNameHash() const override;
        virtual void Update(int64_t a2, float deltaTime) override;
        virtual void UnkFunc3() override;
        virtual void UnkFunc4() override;
        virtual void PML_UnkFunc2() override;
    };
}
