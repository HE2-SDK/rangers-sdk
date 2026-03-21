#pragma once

namespace app::player {
    class PlayerStateParameter : public hh::fnd::BaseObject {
    public:
        csl::ut::MoveArray<StateParameter*> stateParameters;

        DEFAULT_CREATE_FUNC(PlayerStateParameter)

        StateParameter* GetByNameHash(unsigned int nameHash) const;
        void AddParam(const StateParameter& param);
    };
}
