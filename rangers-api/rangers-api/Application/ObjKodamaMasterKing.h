#pragma once

namespace app{
    class ObjKodamaMasterKingInfo : public hh::game::ObjInfo {
    public:
        hh::gfx::ResModel* kodamaKingModel;
        hh::gfx::ResModel* expertKingBaseModel;
        hh::anim::ResSkeletonPxd* kodamaKingSkl;
        hh::fnd::Reference<hh::anim::AsmResourceManager> kodamaKingAsm;
        hh::fnd::Reference<hh::fnd::ResReflectionT<heur::rfl::ObjKodamaMasterKingConfig>> kodamaKingConfig;
        int64_t qword60;
        hh::animeff::ResParticleLocation* kodamaKingEffdb;

        virtual void Load() override;
        virtual void Initialize(hh::game::GameManager* gameManager) override;
        virtual const char* GetInfoName() override;

        OBJINFO_CLASS_DECLARATION_INLINE(ObjKodamaMasterKingInfo);
    };

    class ObjKodamaMasterKing : public hh::game::GameObject, public game::ContactListener, game::GOCEventListener {
    public:
        int overlayJobId;
        char byte25C;
        int dword260;
        player::CharacterIdU8 characterId;
        char byte265;
        char byte266;
        short word268;
        short word26A;
        char byte26C;
        int dword270;
        char byte274;
        char byte275;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
        virtual void OnContact() override;
        virtual void EventCallback(unsigned int event) override {}

        GAMEOBJECT_CLASS_DECLARATION(ObjKodamaMasterKing);
    };
}
