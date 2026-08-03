#pragma once

namespace hh::font{
    class IFont : public hh::fnd::ReferencedObject {
    public:
        short word18;
        int sizesCount;
        int currentSizeIdx;
        int dword24;
        float dword28;
        float dword2C;
        int dword30;
        int64_t qword38;

        virtual void* GetRuntimeTypeInfo() const;
        virtual bool F_UnkFunc0(int64_t a2, int64_t a3, int64_t a4) = 0;
        virtual void F_UnkFunc1() {}
        virtual void F_UnkFunc2() {}
        virtual void F_UnkFunc3() {}
        virtual bool IsLoaded() = 0;
        virtual const char* GetFontName() = 0;
        virtual bool IsCharacterSupported(unsigned short charcode) = 0;
        virtual bool GetGlyphMapData(unsigned int a2, int64_t a3) = 0;
        virtual bool GetGlyphMapData(unsigned int a2, unsigned short a3, int64_t a4) = 0;
        virtual int64_t GetTexture(int fontSizeIdx, int unk0) = 0;
        virtual int GetFontSize(int idx) = 0;
        virtual float F_UnkFunc11() = 0;
        virtual float F_UnkFunc12(int a2) = 0;
        virtual void F_UnkFunc13(float a2) = 0;
        virtual bool GetKerningImpl(unsigned int fontSizeIdx, unsigned short unk0, unsigned short unk1, int64_t unk2) { return 0; }
        virtual char F_UnkFunc15() { return 0; }
        virtual char F_UnkFunc16() { return 0; }
        virtual void F_UnkFunc17() {}

        IFont(csl::fnd::IAllocator* allocator);
    };
}
