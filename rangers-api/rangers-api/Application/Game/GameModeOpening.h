#pragma once

namespace app::game {
    class GameModeOpening : public GameMode {
    public:
        int unk0;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void Initialize() override;
        virtual void UnkFunc9() override;
        virtual void Update(const hh::fnd::SUpdateInfo& updateInfo) override;
        void InitializeServices();

        GameModeOpening(csl::fnd::IAllocator* allocator);
    };
}
