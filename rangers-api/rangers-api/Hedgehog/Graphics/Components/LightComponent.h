#pragma once

namespace hh::gfx {
    class LightComponent : public RenderingComponent {
        class Impl : public fnd::ReferencedObject {
        public:
            class Listener {
            public:
                virtual ~Listener();
                virtual void LightAddedCallback(const fnd::ResLightParameter& lightParameter, unsigned int lightId, const char* sceneName) {}
                virtual void LightRemovedCallback(unsigned int lightId, const char* sceneName) {}
            };

            class MyReloadListener : public fnd::ReloaderListener {
                Impl* lightComponentImplementation;
            };

            void MakeLocalLightParam(needle::FxLightParam* lightParam, const fnd::ResLightParameter& resource);

        private:
            csl::ut::MoveArray<Listener*> listeners;
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

        int AddLocalLightResource(const fnd::ResLightParameter& lightParameter, const char* name, const char* sceneName);
        bool SetLocalLightResource(unsigned int lightId, const fnd::ResLightParameter& lightParameter, const char* sceneName);
        void RemoveLocalLightResource(unsigned int lightId, const char* sceneName);
        unsigned int GetLocalLightCount(const char* sceneName) const;
        unsigned int GetLocalLightMax(const char* sceneName) const;
    };
}
