#pragma once

namespace app::ui {
    struct CaptionCollection {
        struct Caption {
            csl::ut::String label;
            csl::ut::String cue;
            float duration;
            unsigned int unk1;
        };

        struct AddInfo {
            csl::fnd::IAllocator* allocator;
        };

        csl::ut::MoveArray<Caption> items;

        CaptionCollection(csl::fnd::IAllocator* allocator) : items{ allocator } {}
        Caption* Add(const AddInfo& addInfo);
    };

    struct CaptionInfo {
        enum class Style : unsigned char {
            NONE,
            DEFAULT,
            SPARE,
            TOP,
            MIDDLE,
            BOTTOM
        };

        CaptionCollection captions;
        float unk202;
        uint8_t unk206;
        Style style;
        uint8_t renderPriority;
        uint8_t unk209;
        bool unk210; // sets the UICaption object layer to 19 instead of 18
        uint8_t unk211;
    };

    class RequestOverlayCaption : public RequestOverlayBegin, public RequestOverlayTagReplace, public CaptionInfo {
    public:
        CaptionInfo captionInfo;

        DEFAULT_CREATE_FUNC(RequestOverlayCaption);
    };

    class UICaption : public hh::game::GameObject {
    public:
        struct Description {
            RequestOverlayCaption* captionRequest;
        };

        hh::fnd::Reference<RequestOverlayCaption> requestOverlay;
        hh::ui::LayerController* subtitleLc;
        hh::ui::LayerController* textFeedIconLc;
        int currentCaption;
        float currentCaptionDuration;
        hh::snd::SoundHandle subtitleSound;
        char byte26C;
        char byte26D;

		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;

        void Setup(const Description& desc);

        GAMEOBJECT_CLASS_DECLARATION(UICaption);
    };
}
