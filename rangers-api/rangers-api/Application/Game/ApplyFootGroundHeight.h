#pragma once

namespace app::game {
    class ApplyFootGroundHeight : public app_cmn::game::MoveController {
    public:
        hh::game::GOComponent* gocFoot;
        float dword20;

        ApplyFootGroundHeight();

        virtual const char* GetName() override;
        virtual void Update(const hh::fnd::SUpdateInfo& updateInfo) override;
    };
}
