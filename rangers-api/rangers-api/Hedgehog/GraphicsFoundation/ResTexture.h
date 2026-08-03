#pragma once

namespace hh::gfnd {
    class ResTexture : public fnd::ManagedResource {
    public:
        hh::needle::Texture* texture;
        void* unk102[12];
        uint64_t unk103;
        uint64_t unk104;
        uint8_t unk105;
        uint32_t nameHash;

        inline hh::needle::Texture* GetTexture() const { return texture; }
        needle::SurfaceFormat GetFormat() const;
        unsigned int GetHeight() const;
        unsigned int GetMipLevels() const;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResTexture)
    };
}
