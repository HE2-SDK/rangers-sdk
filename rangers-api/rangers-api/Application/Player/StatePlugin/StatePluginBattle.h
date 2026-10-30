#pragma once

namespace app::player {
    class StatePluginBattle : public PlayerStatePlugin {
    public:
        static constexpr const char* name = "StatePluginBattle";

        char byte28;
        float dword2C;
        int64_t qword30;
        int64_t qword38;
        int64_t qword40;
        int64_t qword48;
        int64_t qword50;
        int dword58;
        int dword5C;
        int dword60;
        Timer timer64;
        Timer timer6C;
        int dword74;
        int dword78;
        int dword7C;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginBattle);
    };
}
