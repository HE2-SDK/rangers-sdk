#pragma once

namespace hh::gfx{
    class IBLComponent : public RenderingComponent{
    public:
        class Impl : public fnd::ReferencedObject{
        public:
        };

        fnd::Reference<Impl> implementation;

        IBLComponent(csl::fnd::IAllocator* allocator);

        virtual void Initialize() override {}
        virtual void Deinitialize() override {}
        virtual void UnkFunc3() override {}
        virtual int GetNameHash() override;
        virtual const char* GetName() override;

        void SetIBLTexture(needle::Texture** texture, const char* sceneName);
        void AddProbes(ResProbeData* probeData, float scale, const char* resourceName, const char* sceneName);
        void RemoveProbes(ResProbeData* fallback, float scale, const char* sceneName);
    };
}
