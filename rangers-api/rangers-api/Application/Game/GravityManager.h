#pragma once

namespace app::game {
    class GravityManager : public hh::game::GameService, public hh::game::GameStepListener, public hh::game::EditorStepListener {
    public:
        int unk0;
        csl::ut::LinkList<GOCGravity::GravityPhantom> unk1;
        csl::ut::LinkList<GOCGravity::GravityPhantom> unk2;
        csl::ut::LinkList<GOCGravity::GravityPhantom> unk4;
        csl::ut::LinkList<GOCGravity::GravityPhantom> gravityPhantoms;
        csl::ut::LinkList<GOCGravity::GravityPhantom> unk5;
        csl::math::Vector3 gravityDirection;
        hh::fnd::Reference<hh::ut::AabbTree> aabbTree;
        int64_t unk6;

        virtual void OnAddedToGame() override;
        virtual void OnRemovedFromGame() override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        GAMESERVICE_CLASS_DECLARATION(GravityManager);
    };
}
