#pragma once

namespace app::ui{
    class RequestOverlayToast : public RequestOverlayBegin {
    public:
        csl::ut::MoveArray<int64_t> qword20;
        char pattern;
        char byte41;
        char byte42;
        char byte43;
        csl::ut::String message;
        csl::ut::String soundCueName;
        csl::ut::String qword78;
        csl::ut::String windowTextureName;
        hh::needle::Texture* windowTexture;
        float time;
        char charB4;
        char charB5;
        int dwordB8;
        int dwordBC;
        bool feed;
        char byteC1;
        
        static RequestOverlayToast* Create(csl::fnd::IAllocator* allocator);
    };

    class UIToast : public hh::game::GameObject, public hh::ui::UIListener {
    public:
        struct Description {
            RequestOverlayToast* toastRequest;
        };

        hh::fnd::Reference<RequestOverlayToast> requestOverlay;
        hh::ui::LayerController* mainLc;
        hh::ui::LayerController* textFeedIconLc;
        int dword268;
        char byte26C;

		virtual void AddCallback(hh::game::GameManager* gameManager) override;
        virtual void UIL_UnkFunc1() override;

        void Setup(const Description& desc);

        GAMEOBJECT_CLASS_DECLARATION(UIToast);
    };
}
