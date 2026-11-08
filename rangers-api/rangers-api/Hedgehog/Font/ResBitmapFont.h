#pragma once

namespace hh::font {
    struct BFNT_CHARACTER_TEXTURE_ENTRY {
        float unk0;
        float unk1;
        float unk2;
        float unk3;
        float unk4;
        float unk5;
        float unk6;
        float possiblyCoords[4]; // percentage..?
    };
    struct BFNT_CHUNK {
        float unk0;
        short fontSize;
        short characterCount;
        short kerningCount;
        short unkCount;
        wchar_t* charactersPtr;
        const char** textureName;
        int64_t* unkParam0;
        BFNT_CHARACTER_TEXTURE_ENTRY* characterTextureEntries;
        int64_t* kernings;
        int64_t* unkParam2;
    };
    struct BFNT_ROOT {
        char magic[4];
        uint32_t version;
        char count;
        char defaultFontSizeIdx;
        short unk1;
        char unk3;
        const char* fontName;
        BFNT_CHUNK** chunkPointers;
    };
    class ResBitmapFont : public fnd::ManagedResource {
        BFNT_ROOT* binaryData;
    public:
        static const fnd::ResourceTypeInfo* GetTypeInfo();
        virtual void Load(void* data, size_t size);
        virtual void Unload();
        virtual void Resolve(fnd::ResourceResolver& resolver);
    };
}
