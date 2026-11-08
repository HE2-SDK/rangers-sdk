#pragma once

namespace hh::font{
    class BitmapFont : public IFont {
    public:
        ResBitmapFont* resource;
        csl::ut::MoveArray<float> qword48;
        csl::ut::MoveArray<int> fontSizes;
        csl::ut::MoveArray<csl::ut::MoveArray<fnd::Reference<FontTexture>>> fontTextures;
        float relatedToFontSize;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool F_UnkFunc0(int64_t a2, int64_t a3, int64_t a4) override;
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

        void ClearResource();
        bool SetResource(ResBitmapFont* resource);

        BitmapFont(csl::fnd::IAllocator* allocator);
    };
}
