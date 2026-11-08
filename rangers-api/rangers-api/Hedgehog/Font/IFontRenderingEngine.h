#pragma once

namespace hh::font{
    class IFontRenderingEngine : public hh::fnd::ReferencedObject {
    public:
        struct GlyphInfo {
            float unk0;
            csl::math::Vector2 metrics;
            float horizontalAdvance;
            float topOffset;
            float width;
            float height;
        };

        virtual void* GetRuntimeTypeInfo() const = 0;
        virtual bool OpenFace(int64_t a2) = 0;
        virtual void FRE_UnkFunc1(char a2) = 0;
        virtual void SetFontSize(float newSize) = 0;
        virtual bool GetGlyphInfo(unsigned short charcode, short charsize, GlyphInfo* glyphInfo, char flags) = 0;
        virtual bool FRE_UnkFunc4(int64_t a2, int64_t a3, int64_t a4) = 0;
        virtual bool IsCharacterSupported(unsigned short charcode) = 0;
        virtual float GetScale() = 0;
        virtual float GetAscenderScale() = 0;
        virtual float GetDescenderScale() = 0;
    };
}
