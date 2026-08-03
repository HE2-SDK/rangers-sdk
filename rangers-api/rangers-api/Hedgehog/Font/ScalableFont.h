#pragma once

namespace hh::font{
    class FreeTypeFontRenderingEngine : public IFontRenderingEngine {
    public:
        void* freeTypeLibrary;
        void* freeTypeAllocator;
        void* allocFunc;
        void* freeFunc;
        void* reallocFunc;
        void* freeTypeFace;
        char loadType;
        short word4A;
        short word4C;
        char word4E;
        char word4F;
        float scale;
        float ascenderScale;
        float descenderScale;
        float fontSize;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool OpenFace(int64_t a2) override;
        virtual void FRE_UnkFunc1(char a2) override;
        virtual void SetFontSize(float newSize) override;
        virtual bool GetGlyphInfo(unsigned short charcode, short charsize, GlyphInfo* glyphInfo, char flags) override;
        virtual bool FRE_UnkFunc4(int64_t a2, int64_t a3, int64_t a4) override;
        virtual bool IsCharacterSupported(unsigned short charcode) override;
        virtual float GetScale() override;
        virtual float GetAscenderScale() override;
        virtual float GetDescenderScale() override;

        DEFAULT_CREATE_FUNC(FreeTypeFontRenderingEngine);
    };

    class ScalableFont;

    class ScalableFontEngineAppModule : public fw::AppModule, public csl::fnd::IAllocator {
    public:
        csl::fnd::IAllocator* residentAlloc;
        csl::fnd::Mutex mutex;
        fnd::Reference<FontContainer> fontContainer;
        fnd::ReferencedObject* qword60;
        fnd::ReferencedObject* qword68;
        fnd::ReferencedObject* qword70;
        csl::ut::MoveArray<ScalableFont*> fonts;

        virtual void AddCallback(hh::fw::Application* app) override;
        virtual void RemoveCallback() override;
        virtual void* Alloc(size_t size, size_t alignment) override;
		virtual void Free(void* ptr) override;

        int64_t RegisterFont(ScalableFont* font); // returns font idx

        APPMODULE_CLASS_DECLARATION(ScalableFontEngineAppModule)
    };

    class ScalableFont : public IFont {
    public:
        fnd::Reference<ScalableFontEngineAppModule> scalableFontEngineAppModule;
        ResScalableFontSet* resource0;
        ResScalableFontSet* resource1;
        int64_t qword58;
        int dword60;
        short word64;
        short word66;
        short fontIdx;
        int64_t qword70;
        int64_t qword78;
        int64_t qword80;
        int64_t qword88;
        csl::ut::MoveArray<int64_t> qword90;
        csl::ut::MoveArray<int64_t> qwordB0;
        fnd::Reference<FreeTypeFontRenderingEngine> fontRenderingEngine;
        csl::ut::MoveArray<int64_t> qwordD8;
        char gapF8[24];

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool F_UnkFunc0(int64_t a2, int64_t a3, int64_t a4) override;
        virtual void F_UnkFunc1() override;
        virtual void F_UnkFunc2() override;
        virtual void F_UnkFunc3() override;
        virtual bool IsLoaded() override;
        virtual const char* GetFontName() override;
        virtual bool IsCharacterSupported(unsigned short charcode) override;
        virtual bool GetGlyphMapData(unsigned int a2, int64_t a3) override;
        virtual bool GetGlyphMapData(unsigned int a2, unsigned short a3, int64_t a4) override;
        virtual int64_t GetTexture(int fontSizeIdx, int unk0) override;
        virtual int GetFontSize(int idx) override;
        virtual float F_UnkFunc11() override;
        virtual float F_UnkFunc12(int a2) override;
        virtual void F_UnkFunc13(float a2) override;
        virtual bool GetKerningImpl(unsigned int fontSizeIdx, unsigned short unk0, unsigned short unk1, int64_t unk2) override;
        virtual char F_UnkFunc15() override;
        virtual char F_UnkFunc16() override;
        virtual void F_UnkFunc17() override;

        ScalableFont(csl::fnd::IAllocator* allocator);
    };
}
