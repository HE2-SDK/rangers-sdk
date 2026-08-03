#pragma once

namespace app{
    class ObjNpcSonicInfo : public hh::game::ObjInfo {
    public:
        hh::gfx::ResModel* model;
        hh::anim::ResSkeletonPxd* skl;
        hh::fnd::Reference<hh::anim::AsmResourceManager> asmRes;

        virtual void Load() override;
        virtual void Initialize(hh::game::GameManager* gameManager) override;
        virtual const char* GetInfoName() override;

        OBJINFO_CLASS_DECLARATION_INLINE(ObjNpcSonicInfo)
    };

    class ObjNpcSonic : 
        public ObjNpcBase, 
        public game::ContactListener, 
        public hh::game::GameStepListener 
    {
    public:
        hh::gfx::GOCVisualModel* gocVisualMdl;
        hh::physics::GOCCapsuleCollider* gocCapsuleColl;
        hh::physics::GOCSphereCollider* gocSphereColl;
        bool hasEventName;
        gfx::ModelAnimationPlayer* mdlAnimPlayer;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;

        virtual void OnContact() override;
        virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        GAMEOBJECT_CLASS_DECLARATION(ObjNpcSonic)
    };
}
