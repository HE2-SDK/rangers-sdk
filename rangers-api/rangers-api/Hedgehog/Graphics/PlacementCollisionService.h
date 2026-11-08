#pragma once

namespace hh::gfx {
    class PlacementCollisionService : public game::GameService, public game::GameStepListener {
    public:
        csl::ut::StringMap<int64_t> qword78;
        int64_t qword98;
        int64_t qwordA0;
        char dwordA8;
        int dwordAC;
        int dwordB0;
        int dwordB4;
        char byteB8;
        csl::ut::MoveArray<int64_t> qwordC0;
        csl::math::Vector4 qwordE0[0x10];
        int64_t qword1E0;
        int64_t qword1E8;
        char byte1F0;
        csl::ut::MoveArray<int64_t> qword1F8;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual int64_t UnkFunc0(int64_t a2);
		virtual void PreStepCallback(game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;

        GAMESERVICE_CLASS_DECLARATION(PlacementCollisionService);
    };
}
