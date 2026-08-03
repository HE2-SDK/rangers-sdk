#pragma once

namespace app {
    class ObjDashRingInfo : public hh::game::ObjInfo {
    public:
        struct Visual {
            hh::gfx::ResModel* model;
            hh::gfx::ResAnimTexSrt* uvAnim;

            Visual();
        };

        Visual visuals[4]; // chosen via ObjDashRingSpawner::Visual

        virtual void Initialize(hh::game::GameManager* gameManager) override;
        virtual const char* GetInfoName() override;

        OBJINFO_CLASS_DECLARATION_INLINE(ObjDashRingInfo)
    };
}
