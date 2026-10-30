#pragma once

namespace app::gfx {
    class AuraEffectManager : public hh::game::GameService, public hh::game::GameStepListener {
    public:
        class AuraRenderable : public hh::gfnd::Renderable {
        public:
            AuraEffectManager* manager;

            virtual void Render(const hh::gfnd::RenderableParameter* renderableParameter) override;
        };

        int64_t unk0;
        csl::ut::MoveArray<int64_t> unk2;
        hh::fnd::Reference<AuraRenderable> renderable;
        heur::rfl::GraphicsParameters* graphicsParams;
        char unk4;
        float unk5;
        float unk6;
        float unk7;
        float unk8;
        char unk9[88];
        int64_t unk10;
        Timer unk11;
        char unk12;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;

        virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        void Setup(int64_t unk);

        GAMESERVICE_CLASS_DECLARATION(AuraEffectManager);
    };
}
