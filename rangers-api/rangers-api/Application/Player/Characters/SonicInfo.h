#pragma once

namespace app::player {
    class SonicInfo : public hh::game::ObjInfo {
    public:
        struct MainVisual {
            hh::gfx::ResModel* model;
            hh::gfx::ResModel* auraModel;
            hh::gfx::ResModel* boardModel;
            hh::anim::ResSkeleton* skeleton;
            hh::fnd::Reference<hh::anim::AsmResourceManager> asmResourceManager;
            hh::fnd::Reference<hh::anim::AsmResourceManager> maybeDebugAsmResourceManager;
            hh::fnd::ManagedResource* idleLLoopAnimVis;
            hh::fnd::ManagedResource* idleRLoopAnimVis;
            hh::animeff::ResParticleLocation* particleLocation;
            void* unk2;
            hh::gfx::ResOcclusionCapsule* occlusionCapsule;
            hh::gfx::ResModel* shapeModel;
            hh::anim::ResAnimation* idleAnimation;
        };

        struct SpinVisual {
            hh::gfx::ResModel* model;
            hh::anim::ResSkeleton* skeleton;
            hh::fnd::Reference<hh::anim::AsmResourceManager> asmResourceManager;
            hh::fnd::ManagedResource* animTexSrt;
            hh::animeff::ResParticleLocation* particleLocation;
            hh::gfx::ResOcclusionCapsule* occlusionCapsule;
        };

        MainVisual mainVisual;
        SpinVisual spinVisual;
        hh::gfx::ResModel* dlcKocoToyModel;

        virtual ~SonicInfo() override;
        virtual void Load() override;
        virtual void Initialize(hh::game::GameManager* gameManager) override;
        virtual const char* GetInfoName() override;

        OBJINFO_CLASS_DECLARATION(SonicInfo);
    };
}
