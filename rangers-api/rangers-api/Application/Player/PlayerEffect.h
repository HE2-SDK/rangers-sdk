#pragma once

namespace app::player {
    class PlayerVisual;
    class GOCPlayerVisual;

    class PlayerEffect : public hh::fnd::ReferencedObject {
    public:
        hh::game::GameObject* playerObject;
        PlayerVisual* playerVisual;
        GOCPlayerVisual* gocPlayerVisual;
        GOCPlayerKinematicParams* gocPlayerKinematicParams;
        GOCPlayerBlackboard* gocPlayerBlackboard;
        uint8_t unk1;
        uint8_t unk2;

        CREATE_FUNC(PlayerEffect, hh::game::GameObject* playerObject, PlayerVisual* playerVisual);

        virtual unsigned int GetNameHash() const = 0;
        virtual void Update(int64_t a2, float deltaTime) {}
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
    };
}
