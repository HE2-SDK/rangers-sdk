#pragma once

namespace hh::needle {
    class TextureStreamingTexturePatternGuard : public NeedleRefcountObject {
    public:
        int64_t unk0;
        int64_t unk1;
        Texture** textures;
        unsigned int textureCount;

        TextureStreamingTexturePatternGuard();
    };
}
