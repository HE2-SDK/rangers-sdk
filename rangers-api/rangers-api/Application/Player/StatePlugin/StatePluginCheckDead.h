#pragma once

namespace app::player {
    class StatePluginCheckDead : public PlayerStatePlugin, public PostureListener {
    public:
        struct SetupInfo {
            float deadline;
            float oceanSurface;
            uint8_t unk1;
            float deadFallTime;
        };

        float dword30;
        uint32_t dword34;
        uint8_t byte38;
        uint32_t dword3C;
        csl::math::Vector4 vector40;
        uint32_t dword50;
        uint16_t word54;
        uint64_t qword58;
        uint8_t byte60;
        csl::ut::MoveArray<void*> unk68;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void PL_UnkFunc4() override;

        void Setup(const SetupInfo& setupInfo);

        DEFAULT_CREATE_FUNC(StatePluginCheckDead);
    };
}
