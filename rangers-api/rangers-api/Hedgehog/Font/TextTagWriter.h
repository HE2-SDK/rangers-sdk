#pragma once

namespace hh::font {
    class TextTagWriterFeedListener {
    public:
        virtual ~TextTagWriterFeedListener() = default;
        virtual void TTWFL_UnkFunc1() {}
        virtual void TTWFL_UnkFunc2() {}
        virtual int64_t TTWFL_UnkFunc3() { return 0; }
        virtual int64_t TTWFL_UnkFunc4() { return 0; }
        virtual void TTWFL_UnkFunc5(int64_t a2) {}
        virtual void TTWFL_UnkFunc6() {}
    };

    class ITextWriterBaseExtension {
    public:
        virtual ~ITextWriterBaseExtension();
        virtual int64_t ITWBE_UnkFunc0(unsigned int* a2) {}
    };

    class TextTagWriter;

    class TextTagWriterFeed : public fnd::ReferencedObject {
    public:
        TextTagWriter* textTagWriter;
        int64_t qword20;
        int64_t qword28;
        int64_t qword30;
        int dword38;
        csl::ut::MoveArray<int64_t> qword40;
        csl::ut::MoveArray<int64_t> qword60;
        csl::ut::MoveArray<TextTagWriterFeedListener*> listeners;

        TextTagWriterFeed(csl::fnd::IAllocator* allocator, TextTagWriter* textTagWriter);

        void AddListener(TextTagWriterFeedListener* listener);
    };

    class TextLayouter : public fnd::ReferencedObject {
    public:
        csl::ut::MoveArray<int64_t> qword18;
        int64_t qword38;
        int64_t qword40;
        int64_t qword48;
        int64_t qword50;
        int64_t qword58;
        int64_t qword60;
        int dword68;
        char dword6C;
        float dword70;
        float dword74;
        short word78;
        char byte7A;
        int dword7C;
        int dword80;
        int dword84;
        int dword88;

        TextLayouter(csl::fnd::IAllocator* allocator);
    };

    class TextWriterBaseCommandBuffer : public fnd::ReferencedObject {
    public:
        csl::ut::MoveArray<int64_t> qword18;
        int dword38;

        TextWriterBaseCommandBuffer(csl::fnd::IAllocator* allocator, int a3);
    };

    class TextWriterBase : public fnd::ReferencedObject {
    public:
        struct Context {
            int64_t qword0;
            int64_t qword8;
            int64_t qword10;
            int dword18;
            float dword1C;
            float fontSize;
            int dword24;
            int dword28;
            short currentFontSizeIdx;
            short currentFontIdx; // unsure
            char byte30;
            char byte31;
            char byte32;
            int dword34;
            fnd::Reference<hh::font::IFont> font;
            fnd::Reference<TextRenderer> textRenderer;

            Context();
        };

        fnd::Reference<TextWriterBaseCommandBuffer> commandBuffer;
        csl::ut::MoveArray<fnd::Reference<hh::font::IFont>> fonts;
        fnd::Reference<TextRenderer> textRenderer;
        TextListener* textListener;
        ITextWriterBaseExtension* qword50;
        int dword58;
        float fontSize;
        Context context;

        TextWriterBase(csl::fnd::IAllocator* allocator, TextRenderer* textRenderer, int textLength, hh::font::IFont* font);
        void SetFont(int fontIdx);
        void AddFont(hh::font::IFont* font);
        void SetTextRenderer(TextRenderer* textRenderer);
    };

    class TextTagWriter : public fnd::ReferencedObject, public ITextWriterBaseExtension {
    public:
        class RubyTextWriter : public TextWriterBase, public ITextWriterBaseExtension {
        public:
            TextTagWriter* textTagWriter;
            
            virtual int64_t ITWBE_UnkFunc0(unsigned int* a2) override;
        };

        fnd::Reference<TextWriterBase> textWriterBase;
        fnd::Reference<RubyTextWriter> rubyTextWriter;
        float fontSize0;
        float fontSize1;
        float dword38;
        float dword3C;
        int64_t qword40;
        int64_t qword48;
        ITextWriterBaseExtension* qword50;
        int64_t qword58;
        int64_t qword60;
        short word68;
        int dword6C;
        int dword70;
        short word74;
        int dword78;
        short word7C;
        char byte7E;
        float dword80;
        int64_t qword88;
        int dword90;
        csl::ut::MoveArray<int64_t> qword98;
        csl::ut::MoveArray<int64_t> qwordB8;
        fnd::Reference<TextTagWriterFeed> textTagWriterFeed;
        TextWriterBase::Context context;
        fnd::Reference<TextLayouter> textLayouter;

        TextTagWriter(csl::fnd::IAllocator* allocator, TextRenderer* textRenderer, int textLength, hh::font::IFont* font);

        void AddFont(hh::font::IFont* font);
        void SetTextListener(TextListener* textListener);
        void AddTagWriterFeedListener(TextTagWriterFeedListener* listener);
        void SetTextRenderer(TextRenderer* textRenderer);

        virtual int64_t ITWBE_UnkFunc0(unsigned int* a2) override;
    };
}
