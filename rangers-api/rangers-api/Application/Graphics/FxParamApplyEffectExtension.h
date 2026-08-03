#pragma once

namespace app::gfx {
    class FxParamApplyEffectExtension : public FxParamExtension, public hh::game::GameManagerListener {
    public:
        hh::eff::EffectManager* effectManager;

        FxParamApplyEffectExtension(csl::fnd::IAllocator* allocator);

        virtual void* GetRuntimeTypeInfo() override;
        virtual void Initialize() override;
        virtual void Destroy() override;
        virtual void AfterSetParameter(hh::fnd::SUpdateInfo* updateInfo) override;
        virtual void AfterUpdate(hh::fnd::SUpdateInfo* updateInfo) override;

        virtual void GameServiceAddedCallback(hh::game::GameService* gameService) override;
		virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;
    };
}
