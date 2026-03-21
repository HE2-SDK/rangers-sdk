#pragma once

namespace app::player {
    class StatePluginOutOfControl : public PlayerStatePlugin {
    public:
        static constexpr const char* name = "StatePluginOutOfControl";

        csl::ut::MoveArray<void*> unk201;
        csl::ut::MoveArray<void*> unk202;
        uint16_t unk203;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        void UnkFunc1342(unsigned int nameHash, unsigned int unkParam1);

        DEFAULT_CREATE_FUNC(StatePluginOutOfControl);
    };
}
