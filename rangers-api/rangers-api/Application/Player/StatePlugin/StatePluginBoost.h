#pragma once

namespace app::player {
    class StatePluginBoost : public PlayerStatePlugin, public app::evt::EventPlayerListener {
    public:
        static constexpr const char* name = "StatePluginBoost";

        enum class Flag : unsigned int {
            UNK0,
            UNK1,
            UNK2,
            UNK3,
            UNK4,
            UNK5,
            UNK6,
            UNK7,
            UNK8,
            UNK9,
            UNK10,
            UNK11,
            UNK12,
            UNK13,
            UNK14,
            UNK15,
            UNK16,
        };

        int unk0; //some handle perhaps?
        int unk1;
        int unk2;
        float boostCapacity;
        float boostAmount;
        int unk4;
        float unk5;
        float unk6;
        float unk7; //counter of some sort
        float unk8;
        float unk9; //counter of some sort
        int unk10;
        float infiniteBoostTimer;
        int unk10b;
        int64_t unk11[2];
        hh::hid::VibrationContainer::VibrationObj vibrationObj;
        int64_t unk11b;
        csl::ut::MoveArray<int64_t> unk12;
        csl::ut::MoveArray<int64_t> unk13;
        csl::ut::Bitset<Flag> flags;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;

        virtual void CutsceneEnd(const char* cutsceneName) override;
        virtual void EPL_UnkFunc5() override;

        void SetNitroMode();
        void SetBoostType(uint8_t type);
        void SetUnk1(uint8_t type);
        void PlayShakeEffects();
    
        DEFAULT_CREATE_FUNC(StatePluginBoost);
    };
}
