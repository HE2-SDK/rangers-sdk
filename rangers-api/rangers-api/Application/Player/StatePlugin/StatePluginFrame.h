#pragma once

namespace app::player {
    class StatePluginFrame : public PlayerStatePlugin {
    public:
        csl::ut::MoveArray<void*> unk28;

        virtual unsigned int GetNameHash() const override;
        virtual void RemoveCallback() override;

        DEFAULT_CREATE_FUNC(StatePluginFrame);
    };
}
