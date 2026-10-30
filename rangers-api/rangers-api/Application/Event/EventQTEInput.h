#pragma once

namespace app::evt {
    class MsgDvQTE : public fnd::AppMessage<app::evt::MsgDvQTE> {
    public:
        char unk0;
        const char* cutsceneName;
        dv::DvElementQTE::Description::QTEType qteType;
        dv::DvElementQTE::Description::QTEButton qteButton;
        float redCircleSize;
        float redCircleThickness;
        float whiteLineThickness;
        float whiteLineSpeed;
        float multiplier;
        float redCircleOutlineThickness;
        float whiteLineOutlineThickness;
        int failCount;
        int mashCount;
        csl::math::Vector2 offset;
        float unk4;
        float unk5;
        float unk6;
        float unk7;
        float unk8;
        float unk9;
        float unk10;
        float unk11;
        
        MsgDvQTE() : fnd::AppMessage<MsgDvQTE>{ hh::fnd::MessageID::DV_QTE } {}
    };

    class EventQTEInput : public hh::game::GameObject {
    public:
        struct QTEInfo0 {
            dv::DvElementQTE::Description::QTEButton qteButton;
            float redCircleSize;
            float redCircleThickness;
            float whiteLineThickness;
            float whiteLineSpeed;
            float multiplier;
            float redCircleOutlineThickness;
            float whiteLineOutlineThickness;
            dv::DvElementQTE::Description::QTEType qteType;
            int failCount;
        };

        struct QTEInfo1 {
            int unk4;
            int unk5;
            int unk6;
            int unk7;
            int unk8;
            int unk9;
            int unk10;
            csl::math::Vector2 offset;
        };

        struct Description {
            QTEInfo0 info0;
            int mashCount;
            QTEInfo1 info1;
        };

        hh::game::GOCInput* gocInput;
        char byte250;
        char byte251;
        char byte252;
        char byte253;
        int failHitCount;
        QTEInfo0 qteInfo0;
        int hitCount;
        int mashCount;
        int dword290;
        QTEInfo1 qteInfo1;
        hh::snd::SoundHandle dword2B0;
        hh::gfx::GOCVisualUserModel* mainWhiteLine1;
        hh::gfx::GOCVisualUserModel* mainWhiteLine0;
        csl::ut::MoveArray<hh::gfx::GOCVisualUserModel*> secondaryWhiteLines1;
        csl::ut::MoveArray<hh::gfx::GOCVisualUserModel*> secondaryWhiteLines0;
        float hitCircleSize; // The one that's getting smaller and you have to hit
        float dword2FC;
        int dword310;
        float redCircleMinSize;
        float redCircleMaxSize;
        int dword31C;

		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;

        void Setup(const Description& desc);

        GAMEOBJECT_CLASS_DECLARATION(EventQTEInput);
    };
}
