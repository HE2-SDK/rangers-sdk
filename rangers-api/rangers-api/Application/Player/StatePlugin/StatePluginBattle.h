#pragma once

namespace app::player {
    class StatePluginBattle : public PlayerStatePlugin {
    public:
        uint8_t byte28;
        float dword2C;
        uint64_t qword30;
        csl::ut::MoveArray<void*> unk38;
        hh::snd::SoundHandle unk58;
        uint32_t unk5C;
        uint32_t unk60;
        Timer qword64;
        Timer qword6C;
        uint32_t qword74;
        float qword78;
        unsigned int dword7C;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginBattle);
    };
}
