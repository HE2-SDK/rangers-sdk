#pragma once

namespace hh::gfx {
    class LightComponent : public RenderingComponent {
        class Impl : public fnd::ReferencedObject {
        public:
            class MyReloadListener : public fnd::ReloaderListener {
            public:
                Impl* lightComponentImplementation;

                virtual void PostResourceReloadCallback(fnd::ManagedResource* resource) override;
            };

        private:
            csl::ut::MoveArray<void*> unk1;
            MyReloadListener reloadListener;
        };

        fnd::Reference<Impl> implementation;

    public:
        LightComponent(csl::fnd::IAllocator* allocator);
        virtual void UnkFunc1() override;
        virtual void UnkFunc2() override;
        virtual void UnkFunc3() override {}
        virtual int GetNameHash() override;
        virtual const char* GetName() override;
    };
}
