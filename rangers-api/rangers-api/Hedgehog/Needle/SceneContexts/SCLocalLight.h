#pragma once

namespace hh::gfx {
    class ResMirageLight;
}

namespace hh::needle {
    class SCLocalLight;

    class LocalLightParamBuildJob : public ParamBuildJob {
    public:
        struct LocalLightContextDataCBuffer {
            int lightCount;
            float worldScale;
            float sqrtWorldScale;
            float unk0;
            char lightData[64000];
        };

        SCLocalLight* scLocalLight;
        intrusive_ptr<ConstantBuffer> cbuffer;

        static int64_t cbufferSize;

        virtual void Prepare(ParameterValueObject* parameters, PipelineInfo* pipelineInfo) override;
        virtual void Run(ParamValueOverrideHelper* paramOverrides, PipelineInfo* pipelineInfo, unsigned int viewportId, unsigned int parameterId) override {}
    };

    class SCLocalLight : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
        public:
            struct LightHandle {
                int index;
                CNameIDObject* name;
            };

            SCLocalLight& sceneContext;
            FxLightParam localLightParams[1000];
            unsigned int numLights;
            unsigned int maxLights;
            LightHandle handles[1000];
            unsigned int nextId;
            csl::math::Vector4 unk6;
            float unk7;
            int unk8;
            csl::fnd::Mutex mutex;

            Impl(SCLocalLight& sceneContext);

            FxLightParam* GetLocalLightParam(unsigned int id) const;
        };

        intrusive_ptr<Impl> implementation;
        intrusive_ptr<LocalLightParamBuildJob> paramBuildJob;

        SCENECONTEXT_CLASS_DECLARATION(SCLocalLight);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();

        int AddLocalLightParam(const FxLightParam& lightParam, const char* name);
        bool SetLocalLightParam(unsigned int id, const FxLightParam& lightParam);
        void RemoveLocalLightParam(unsigned int lightId);
        unsigned int GetLocalLightCount() const;
        unsigned int GetLocalLightMax() const;
    };
}
