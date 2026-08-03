#pragma once

namespace hh::gfx {
    class ResProbeData;
}

namespace hh::needle {
    class SCIBL : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
        public:
            SCIBL& sceneContext;
            intrusive_ptr<Texture> iblTexture;
            intrusive_ptr<ProbeBVH> probeBVH;
            RenderingDeviceContext* renderingDeviceContext;
            csl::math::Vector3 probeLocationsMaybe[24];
            unsigned int unk2;

            Impl(SCIBL& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCIBL);

        virtual void Initialize(const InitializeInfo& initializeInfo) override;
        virtual void UnkFunc1() override;
        virtual void UnkFunc2() override;
        virtual unsigned int GetNameHash() override;
        virtual const char* GetName() override;

        void AddProbes(SupportFXAll* supportFX, hh::gfx::ResProbeData* probeData, float scale, const char* resourceName);
        const csl::math::Vector3& GetProbeLocation(unsigned int idx) const;
        void SetIBLTexture(Texture* texture);
        intrusive_ptr<Texture>& GetIBLTexture() const;
        ProbeBVH* GetProbeBVH() const;
    };
}
