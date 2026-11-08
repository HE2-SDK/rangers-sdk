#pragma once

namespace app::game {
    class GameModeStage : public GameMode, public app::save::SaveManagerListener {
    public:
        class State {
        public:
            class BuildBase : public hh::ut::StateBase<GameModeStage> {
            };

            class RebuildLevel : public BuildBase {
                uint32_t unk3;
                uint64_t unk4;
                uint64_t unk5;
                bool unk6;
                uint32_t unk7;
                uint32_t unk8;
                uint16_t unk9;

                void InitializeCockpit(GameModeStage* gameMode);
            };
        };

        struct Description{

        };

        int64_t unk0;
        const char* stageCode;
        int64_t unk1;
        int64_t unk2;
        int64_t unk3;
        int unk4;
        int64_t unk5;
        int64_t unk6;
        int64_t unk7;
        int64_t unk8;
        int unk9;
        float unk10;
        int unk11;
        char unk12;
        int unk13;
        int unk14;
        char unk15;
        char unk16;
        char unk17;
        char unk18;
        char unk19;
        char unk20;
        char unk21;
        char unk22;
        char unk23;
        char unk24;
        bool unk25;
        char unk26;
        char unk27;
        char unk28;
        char unk29;
        char unk30;
        char stageId[16];
        char unkName[32];
        csl::ut::MoveArray<int64_t> unk31;
        int64_t uiIndicatorLifeTime;
        csl::ut::InplaceMoveArray<int, 4> unk33;
        csl::ut::InplaceMoveArray<int, 4> unk34;
        csl::ut::InplaceMoveArray<int, 4> unk35;
        int64_t unk36; //flags, 0x147BFB0CB
        char nextStageId[16];
        ApplicationSequenceExtension::Unk2 unk37;
        int unk38;
        hh::fnd::WorldPosition unk39;
        hh::fnd::WorldPosition unk40;
        hh::fnd::WorldPosition unk41;
        int64_t unk42;
        char unk43;
        int64_t unk44;
        csl::math::Vector4 unk45;
        int unk46;
        csl::fnd::Mutex unk47;
        int celebrationOverlayId;
        uint8_t characterId;

		virtual void* GetRuntimeTypeInfo() const override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void Initialize() override;
        virtual void Deinitialize(bool a2) override;
        virtual void UnkFunc7() override;
        virtual void UnkFunc8() override;
        virtual void UnkFunc9() override;
        virtual void UnkFunc10() override;
        virtual int Shutdown() override;
        virtual void UnkFunc13() override;

        virtual void SML_UnkFunc2() override;

        void InitializeServices();
        void InitializeModules();

        GameModeStage(csl::fnd::IAllocator* allocator, Description& desc);
    };
}
