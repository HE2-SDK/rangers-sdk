#pragma once

namespace app::evt{
    class ObjEventStageResolver : public hh::game::GameObject {
    public:
        csl::ut::VariableString cutsceneName;
        csl::ut::VariableString stageName;
        hh::fnd::Reference<hh::game::LevelLoader> levelLoader;
        hh::dv::DiEventManager* diEvtMgr;
        hh::fnd::Handle<hh::dv::DvSceneControl> dvSceneControl;

        virtual void AddCallback(hh::game::GameManager* gameManager) override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(ObjEventStageResolver);
    };
}
