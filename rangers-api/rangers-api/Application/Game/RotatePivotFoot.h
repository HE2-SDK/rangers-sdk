#pragma once

namespace app::game{
    class RotatePivotFoot : public app_cmn::game::MoveController {
    public:
        static const char* name;

        int64_t unk0;
        float unk1;
        float unk2;
        int unk3;
        csl::math::Vector4 unk4;
        csl::math::Vector4 unk5;
        bool hasUnk5;

        virtual const char* GetName() override;
        virtual void Update(const hh::fnd::SUpdateInfo& updateInfo) override;

        RotatePivotFoot();
    };
}
