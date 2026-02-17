#pragma once

namespace app::player {
    class StatePluginCyloop : public PlayerStatePlugin {
    public:
        uint8_t gap28[72];
        uint64_t qword70;
        void* calculator;
        csl::ut::MoveArray<void*> unk80;
        uint64_t qwordA0;
        uint32_t dwordA8;
        uint32_t dwordAC;
        uint64_t qwordB0;
        uint32_t dwordB8;
        float dwordBC;
        uint32_t dwordC0;
        uint8_t byteC4;
        uint64_t qwordC8;
        uint16_t wordD0;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;

        DEFAULT_CREATE_FUNC(StatePluginCyloop);
    };
}
