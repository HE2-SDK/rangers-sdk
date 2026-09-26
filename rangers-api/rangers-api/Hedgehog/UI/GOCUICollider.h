#pragma once

namespace hh::ui {
    class GOCUICollider : public game::GOComponent {
    public:
        int dword80;
        csl::ut::MoveArray<fnd::Reference<UICollider>> colliders;
        game::GameService* uiCollisionWorld;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;

        void AddCollider(UICollider* collider);
        UIColliderPane* AddPaneCollider(int priority, fnd::Handle<SurfRideCastHandle>& cast);

        GOCOMPONENT_CLASS_DECLARATION(GOCUICollider);
    };
}