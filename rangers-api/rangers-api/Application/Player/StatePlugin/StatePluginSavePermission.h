#pragma once

namespace app::player {
    class StatePluginSavePermission : public PlayerStatePlugin {
    public:
        csl::ut::InplaceMoveArray<unsigned int, 4> unk201;
        csl::ut::InplaceMoveArray<unsigned int, 4> unk202;
        csl::ut::InplaceMoveArray<unsigned int, 4> unk203;
        uint16_t unk204;
        uint8_t unk205;

        virtual unsigned int GetNameHash() const override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginSavePermission);
    };
}
