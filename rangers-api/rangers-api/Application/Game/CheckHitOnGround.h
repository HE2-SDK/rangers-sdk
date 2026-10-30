#pragma once

namespace app::game {
    class CheckHitOnGround : public app_cmn::game::MoveController {
    public:
        static const char* name;

        csl::ut::MoveArray<int64_t> qword18;
        float dword38;
        int dword3C;
        int dword40;
        float dword44;
        int dword48;
        char byte4C;
        int dword50;
        char byte54;

        virtual const char* GetName() override;
        virtual void Update(const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void AddCallback() override;

        CheckHitOnGround(csl::fnd::IAllocator* allocator);
    };
}
