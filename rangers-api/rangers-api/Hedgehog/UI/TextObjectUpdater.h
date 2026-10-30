#pragma once

namespace hh::ui {
    class TextObjectUpdaterListener {
    public:
        virtual ~TextObjectUpdaterListener();
        virtual void TOUL_UnkFunc1() {}
        virtual void TOUL_UnkFunc2() {}
    };

    class UIManager;
    class TextObjectUpdater : public fnd::ReferencedObject, public TextFeedTriggerControllerListener {
    public:
        csl::ut::MoveArray<void*> unk1; // delegates
        csl::ut::MoveArray<void*> unk2;
        csl::ut::MoveArray<void*> unk3;
        csl::ut::MoveArray<void*> unk4;
        csl::ut::MoveArray<void*> unk5;
        bool unk6;
        fnd::Handle<SurfRideCastHandle> hCast;
        csl::ut::VariableString textTag;
        UITextInterface* textInterface;
        fnd::Handle<GOCSprite> hGOCSprite;
        UIManager* uiManager;
        fnd::Reference<TextObject> textObject;
        fnd::Reference<TextObjectCastAdapter> textObjectCastAdapter;
        fnd::Reference<TextFeedAnimationController> textFeedAnimationController;
        fnd::Reference<TextFeedTriggerController> textFeedTriggerController;
        void* unk12; // set in constructor
        text::TagReplacer* tagReplacer;
        csl::ut::MoveArray<TextObjectUpdaterListener*> listeners;
        bool unk15a;
        bool unk15b;
        uint32_t localeIndex;

        TextObjectUpdater(csl::fnd::IAllocator* pAllocator, UITextInterface* textInterface, GOCSprite* gocSprite, SurfRide::Cast* cast, void* unkParam1);
        void AddListener(TextObjectUpdaterListener* listener);
        void RemoveListener(TextObjectUpdaterListener* listener);
        void SetLocalizationVariable(const char* name, const char* value);
        void SetLocalizationTag(const char* name);
        void SetText(const char* text, unsigned int unkParam1);
        void Clear();
        bool LoadTextParameters(csl::ut::VariableString& text, TextStyleParameters& styleParams);
        void SetTextData(TextData* textData);
        void SetStyleParameters(const TextStyleParameters& styleParams);
        void Update();
        text::TagReplacer& GetTagReplacer();

        virtual void TFTCL_UnkFunc0(int64_t a2) override;
    };
}
