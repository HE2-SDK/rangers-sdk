#pragma once

namespace app::ui {
    class RequestOverlayCaptionSelectBox : public RequestOverlayBegin {
    public:
        RequestOverlayTagReplace overlayTagReplace;
        csl::ut::String subtitleText;
        csl::ut::String subtitleSound;
        float time;
        csl::ut::MoveArray<csl::ut::String> options;
        int defaultSelectedOption;
        float dword9C;
        char wordA0;
        char wordA1;
        bool subtitleLoop;

        inline RequestOverlayCaptionSelectBox(csl::fnd::IAllocator* allocator) : 
            RequestOverlayBegin{ allocator }, 
            overlayTagReplace{ allocator },
            subtitleText{ allocator },
            subtitleSound{ allocator },
            options{ allocator } 
        {}
        static RequestOverlayCaptionSelectBox* Create(csl::fnd::IAllocator* allocator);
    };

    class UICaptionSelectBox : public hh::game::GameObject, public hh::ui::UIListener {
    public:
        struct Description {
            RequestOverlayCaptionSelectBox* selectBoxRequest;
        };

        hh::fnd::Reference<RequestOverlayCaptionSelectBox> requestOverlay;
        hh::ui::LayerController* subtitleLc;
        hh::ui::LayerController* textFeedIconLc;
        hh::ui::LayerController* dialogChoiceLc;
        float dword270;
        float dword274;
        hh::snd::SoundHandle subtitleSound;
        hh::fnd::Handle<hh::game::GameObject> controlGuide;
        int dword280;
        char flags;

		virtual void AddCallback(hh::game::GameManager* gameManager) override;
        virtual void UIL_UnkFunc1() override;

        void Setup(const Description& desc);

        GAMEOBJECT_CLASS_DECLARATION(UICaptionSelectBox);
    };
};
