#pragma once

namespace hh::font {
    class TextRenderer : public fnd::ReferencedObject {
    public:
        int dword18;

        virtual int64_t TR_UnkFunc0(int a2, int64_t a3, int a4, int64_t a5, int a6, int a7, int64_t a8) = 0;
        virtual int64_t TR_UnkFunc1(int64_t a2, int a3, int64_t _R9) = 0;
        virtual int64_t TR_UnkFunc2() = 0;
    };

    class TextRendererSimple : public TextRenderer {
    public:
        virtual int64_t TR_UnkFunc0(int a2, int64_t a3, int a4, int64_t a5, int a6, int a7, int64_t a8) override;
        virtual int64_t TR_UnkFunc1(int64_t a2, int a3, int64_t _R9) override;
        virtual int64_t TR_UnkFunc2() override;

        TextRendererSimple(csl::fnd::IAllocator* allocator);
    };
}
