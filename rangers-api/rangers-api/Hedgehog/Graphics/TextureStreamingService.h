#pragma once

namespace hh::gfx{
    class MTLoadingThreadDispacher;

    class TextureStreamingService : public game::GameService, public game::GameUpdateListener{
    public:
        rsdx::SJobJoint* unk0;
        MTLoadingThreadDispacher* threadDispacher;
        int unk2;
        bool update;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void Setup(int unk0) {}
        virtual void PreGameUpdateCallback(game::GameManager* gameManager, const fnd::SUpdateInfo& updateInfo) override;

        GAMESERVICE_CLASS_DECLARATION(TextureStreamingService);
    };
}
