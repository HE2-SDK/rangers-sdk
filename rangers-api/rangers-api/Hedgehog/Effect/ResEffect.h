#pragma once

namespace hh::eff {
    class ResEffect : public fnd::ManagedResource {
    public:
        uint8_t unk101;
        csl::ut::StringMap<fnd::Reference<ResEffect>> childEffectsByName; // something with child effects, see 1.42 0x140215a20
        csl::ut::MoveArray<const char*> childEffectNames;
        csl::ut::StringMap<fnd::Reference<hh::gfnd::ResTexture>> texturesByName;
        hh::fnd::Reference<hh::gfx::ResModel> model;
        hh::needle::intrusive_ptr<hh::needle::Texture> gpuEffectRenderTarget1;
        hh::needle::intrusive_ptr<hh::needle::Texture> gpuEffectRenderTarget2;
        hh::needle::intrusive_ptr<hh::needle::Texture> vectorFieldTexture;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Resolve(fnd::ResourceResolver& resolver) override;
        virtual void Reload(void* data, size_t size) override {}

        MANAGED_RESOURCE_CLASS_DECLARATION(ResEffect)

        Cyan::Resource::EffectParam* GetEffectParam() const;
        ResEffect* GetChildEffect(const char* name) const;
        hh::gfnd::ResTexture* GetTexture(const char* name) const;
        hh::gfx::ResModel* GetModel() const;
    };
}
