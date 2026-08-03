#pragma once

namespace hh::gfx {
    class InteractionComputeService : public game::GameService, public game::GameStepListener {
    public:
        csl::ut::MoveArray<int64_t> unk0;
        int unk1;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void PreStepCallback(game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;

        void Setup(int size);

        GAMESERVICE_CLASS_DECLARATION(InteractionComputeService);
    };
}
