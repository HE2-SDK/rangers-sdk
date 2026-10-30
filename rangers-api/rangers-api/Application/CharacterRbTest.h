#pragma once

namespace app {
    class CharacterRbTest : public hh::game::GameObject {
    public:
        int64_t qword248;
        int64_t qword250;
        hh::game::GOComponent* gocCharacterController;
        hh::game::GOComponent* gocCharacterController2;
        int64_t qword268;
        game::GOCGravity* gocGravity;
        csl::math::Vector3 position;

        virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(CharacterRbTest);
    };
}
