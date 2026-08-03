#pragma once

namespace app::player {
    class PlayerBlackboardService : public hh::game::GameService {
    public:
        csl::ut::MoveArray<int64_t> unk0;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual bool ReceiveMessage(hh::fnd::Message& message) override;
		virtual void OnRemovedFromGame() override;

        GAMESERVICE_CLASS_DECLARATION(PlayerBlackboardService)
    };
}
