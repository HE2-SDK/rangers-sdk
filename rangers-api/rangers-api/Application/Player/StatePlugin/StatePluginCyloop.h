#pragma once

namespace app::player {
    class PlayerCyloopCalculator : public hh::fnd::BaseObject {
    public:
        float unk0; // 100 when normal, 400 when super
        float unk1; // 0.5 when normal, 2 when super
        int64_t unk2;
        int64_t unk3;
        int64_t unk4;
        int64_t unk5;
        int64_t unk6;
        csl::fnd::IAllocator* unk7;
        csl::ut::MoveArray<int64_t> unk8;
        int64_t unk9;
        int64_t unk10;
        int64_t unk11;
        int unk12;
        short unk13;

        PlayerCyloopCalculator(csl::fnd::IAllocator* allocator, float unk0, float unk1);
    };

    class StatePluginCyloop : public PlayerStatePlugin {
    public:
        static constexpr const char* name = "StatePluginCyloop";

        hh::ut::TinyFsm<StatePluginCyloop> fsm;
        hh::fnd::Reference<PlayerStatePlugin> cyloopSlash;
        PlayerCyloopCalculator* calculator;
        csl::ut::MoveArray<int64_t> unk1;
        int unk2; // handle of some sort
        int comboCounter;
        float cyloopTime; // For how long the Cyloop's been held
        hh::snd::SoundHandle sound;
        float unk5;
        float unk5b;
        int unk6;
        float unk7;
        int unk8;
        char unk9;
        float cooldownTimer;
        float unk10;
        short flags; // |= 0x100 when super, |= 0x200 when GetStageIndex returns 3

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;

        StatePluginCyloop(csl::fnd::IAllocator* allocator);
    };
}
