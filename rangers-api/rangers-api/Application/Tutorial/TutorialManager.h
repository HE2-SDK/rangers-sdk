#pragma once

namespace app::tutorial {
    class TutorialManager : public hh::game::GameService, public hh::game::GameStepListener {
    public:
        int dword78[7];
        int dword94;
        short word98;
        int dword9C;
        short wordA0;
        int dwordA4;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnRemovedFromGame() override;

		virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        GAMESERVICE_CLASS_DECLARATION(TutorialManager);
    };
}
