#pragma once

namespace app::game{
    class GameModeFishing : public GameMode{
    public:
        class State {
        public:
            class StageTop : public hh::ut::StateBase<GameModeFishing> {
            public:
                int unk0;

                virtual bool Init(GameModeFishing& context) override;
                virtual void Enter(GameModeFishing& context, int previousState) override;
                virtual void Leave(GameModeFishing& context, int nextState) override;
                virtual bool Step(GameModeFishing& context, float deltaTime) override;

                DEFAULT_CREATE_FUNC(StageTop);
            };

            class Build : public hh::ut::StateBase<GameModeFishing> {
            public:
                int64_t unk0;

                virtual bool Init(GameModeFishing& context) override;

                DEFAULT_CREATE_FUNC(Build);
            };

            class BuildBase : public hh::ut::StateBase<GameModeFishing> {
            public:
            };

            class BuildLevel : public BuildBase {
            public:
                char unk0;
                int unk1;

                virtual void Enter(GameModeFishing& context, int previousState) override;
                virtual void Leave(GameModeFishing& context, int nextState) override;
                virtual bool Step(GameModeFishing& context, float deltaTime) override;

                DEFAULT_CREATE_FUNC(BuildLevel);
            };

            class DestroyLevel : public BuildBase {
            public:
                virtual void Enter(GameModeFishing& context, int previousState) override;
                virtual void Leave(GameModeFishing& context, int nextState) override;
                virtual bool Step(GameModeFishing& context, float deltaTime) override;

                DEFAULT_CREATE_FUNC(DestroyLevel);
            };

            class PlayTop : public hh::ut::StateBase<GameModeFishing> {
            public:
                virtual void Enter(GameModeFishing& context, int previousState) override;

                DEFAULT_CREATE_FUNC(PlayTop);
            };

            class Play : public hh::ut::StateBase<GameModeFishing> {
            public:
                virtual bool ProcessMessage(GameModeFishing& context, const hh::fnd::Message& message) override;
                virtual bool Step(GameModeFishing& context, float deltaTime) override;

                DEFAULT_CREATE_FUNC(Play);
            };

            class Finish : public hh::ut::StateBase<GameModeFishing> {
            public:
                virtual void Enter(GameModeFishing& context, int previousState) override;
                virtual bool Step(GameModeFishing& context, float deltaTime) override;

                DEFAULT_CREATE_FUNC(Finish);
            };

            class GameEditor : public hh::ut::StateBase<GameModeFishing> {
            public:
                int unk0;
                int unk1;

                virtual void Enter(GameModeFishing& context, int previousState) override;
                virtual void Leave(GameModeFishing& context, int nextState) override;
                virtual bool Step(GameModeFishing& context, float deltaTime) override;

                DEFAULT_CREATE_FUNC(GameEditor);
            };
        };

        struct UnkStr{
            const char* unk0;
            const char* unk1;
            int64_t unk2;
            int16_t unk3;
            bool unk4;
        };

        UnkStr unkStr;
        char unk5[16];
        char unk6[32];
        int64_t uiIndicatorLifeTime;
        char fflags; //0x01 - shutdowned
        int stateNameHash;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void Initialize() override;
        virtual void Deinitialize(bool a2) override;
        virtual void UnkFunc9() override;
        virtual void UnkFunc10() override;
        virtual int Shutdown() override;
        virtual void UnkFunc13() override;

        GameModeFishing(csl::fnd::IAllocator* allocator, UnkStr& unkStr);
    };
}
