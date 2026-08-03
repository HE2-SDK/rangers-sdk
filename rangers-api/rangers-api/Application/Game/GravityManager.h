#pragma once

namespace app::game {
    class GravityManager : public hh::game::GameService, public hh::game::GameStepListener, public hh::game::EditorStepListener {
    public:
        class UnkStr : public hh::ut::KdTreeBuilder {
        public:
            void* unk0;
            void* unk1;
        };

        int unk0;
        UnkStr unk1[5];
        csl::math::Vector4 unk2;
        hh::ut::AabbTree* aabbTree;
        int64_t unk3;

        virtual void OnAddedToGame() override;
        virtual void OnRemovedFromGame() override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        GAMESERVICE_CLASS_DECLARATION(GravityManager);
    };
}
