#pragma once

namespace app::ui{
    class UIBossLife : public hh::game::GameObject {
    public:
        hh::ui::LayerController* lifeGaugeController;
        hh::ui::LayerController* refGaugeController;
        hh::ui::LayerController* refGaugeSubController;
        float size;
        int dword264;
        bool stunned;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;

        GAMEOBJECT_CLASS_DECLARATION(UIBossLife);
    };
}
