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
            struct LightResource {
                unsigned int id;
                gfx::ResMirageLight* resource;
            };

            struct LightData {
                float color[3];
                int probablyLightType;
                float position[3];
                float radius;
                float rotation[4];
                float unk0;
                float unk1;
                float unk2;
                float shadowsRelated;
            };

            SCLocalLight& sceneContext;
            LightData lightData[1000];
            unsigned int numLights;
            unsigned int maxLights;
            LightResource lightResources[1000];
            unsigned int lastLightRemovedIdx;
            csl::math::Vector4 unk6;
            float unk7;
            int unk8;
            csl::fnd::Mutex mutex;

            Impl(SCLocalLight& sceneContext);
            LightData& GetLightDataByIdx(const unsigned int idx);
        };

        intrusive_ptr<Impl> implementation;
        intrusive_ptr<LocalLightParamBuildJob> paramBuildJob;

        SCENECONTEXT_CLASS_DECLARATION(SCLocalLight);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();

        void SetLightDataByIdx(const unsigned int idx, const Impl::LightData& lightData);
    };
}
