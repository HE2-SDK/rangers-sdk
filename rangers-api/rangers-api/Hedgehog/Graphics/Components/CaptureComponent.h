#pragma once

namespace hh::gfx {
    class CaptureComponent : public RenderingComponent {
    public:
        class Listener {
        public:
            virtual void CCL_UnkFunc0() = 0;
            virtual int64_t CCL_UnkFunc1() = 0;
            virtual void CCL_UnkFunc2() = 0;
        };

        class Impl : public fnd::ReferencedObject {
        public:
            class MyCaptureListener : public needle::SupportFX::CaptureIBLListener {
                Impl* captureComponentImplementation;
                needle::intrusive_ptr<needle::DefaultCaptureRenderingPipeline> defaultRenderingPipeline;
                needle::intrusive_ptr<needle::ImpostorCaptureRenderingPipeline> impostorRenderingPipeline;
                needle::intrusive_ptr<needle::BlendModelCaptureRenderingPipeline> blendModelRenderingPipeline;

                virtual void CIL_UnkFunc0() override;
                virtual void CIL_UnkFunc1() override;
                virtual void CIL_UnkFunc2() override;
            };

        private:
            csl::ut::InplaceMoveArray<Listener*, 1> listeners;
            uint64_t unk2;
            uint64_t unk3;
            MyCaptureListener captureListener;
        };

        fnd::Reference<Impl> implementation;

        CaptureComponent(csl::fnd::IAllocator* allocator);
        virtual void Initialize() override;
        virtual void Deinitialize() override;
        virtual void UnkFunc3() override {}
        virtual int GetNameHash() override;
        virtual const char* GetName() override;

        void AddListener(Listener* listener);
    };
}
