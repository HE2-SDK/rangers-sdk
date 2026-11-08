#pragma once

namespace app::game{
    class ReactiveListener {
    public:
        virtual int64_t RL_UnkFunc0() {}
    };

    class ReactiveService : public hh::game::GameService, public hh::game::GameStepListener {
    public:
        class ReactiveData : public hh::fnd::ReferencedObject {
        public:
            ReactiveListener* listener;
            int unk0;
        };

        csl::ut::MoveArray<hh::fnd::Reference<ReactiveData>> reactiveDatas[10];
        csl::ut::MoveArray<ReactiveListener*> listeners;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;

        virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        GAMESERVICE_CLASS_DECLARATION(ReactiveService);
    };
}
