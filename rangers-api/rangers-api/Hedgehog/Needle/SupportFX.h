#pragma once
#include <ucsl/resources/shlightfield/v1.h>

namespace hh::needle {
    class PBRModelInstanceRenderer;
    class CopyColor;
    class RenderUnit;
    class RenderTextureHandle;
    class RenderTextureCreateArgs;
    class SupportFX;

    class FxPerformanceCounter {
    public:
        virtual void BeginPerformanceCounter(SupportFX* supportFx) {}
        virtual void EndPerformanceCounter(SupportFX* supportFx) {}
        virtual void DrawPerformanceCounter() {}
    };

    class SupportFX {
    public:
        struct FxViewport {
            FxCamera* camera;
            uint32_t x;
            uint32_t y;
            uint32_t resX;
            uint32_t resY;
            uint32_t prevRenderResX;
            uint32_t prevRenderResY;
            uint32_t renderResX;
            uint32_t renderResY;
            uint32_t unk7;
        };

        struct FxRenderParam {
            // uint8_t unk1[240];
            // uint32_t unk2;
            // uint32_t unk3;
            // uint32_t unk4;
            // uint32_t unk5;
            // uint32_t unk6;
            FxViewport viewports[5];
            uint32_t numViewports;
            float clearColor[4];
        };

        struct LightFieldDescription {
            ucsl::resources::shlightfield::v1::SHLightFieldData* binaryData;
            csl::ut::MoveArray<hh::needle::Texture*>* textures;
        };

        class CaptureIBLListener {
        public:
            virtual void CIL_UnkFunc0() = 0;
            virtual void CIL_UnkFunc1() = 0;
            virtual void CIL_UnkFunc2() = 0;
        };

        class SFXAllocator : public csl::fnd::IAllocator {
        public:
            struct ProbeNode {
                int probeCounts[3];
                csl::math::Matrix44 transform;
                csl::math::Matrix44 transform1;
                intrusive_ptr<Texture> texture;
                char byte98;
                float dword9C;
                float dword100;
                float dword104;
                int dword108;
            };

            SupportFX* supportFx;
            char byte10;
            float defaultProbeLightingData[36];
            csl::ut::MoveArray<ProbeNode> probeNodes;
            csl::ut::MoveArray<ProbeNode> qwordC8;
            csl::ut::MoveArray<int64_t> qwordE8;
            intrusive_ptr<PickColorShaderObject> pickColorShaderObject;

            inline SFXAllocator() {}
            virtual ~SFXAllocator();
            
            virtual void* Alloc(size_t in_size, size_t in_alignment) override;
            virtual void Free(void* in_pMemory) override;

            static SFXAllocator instance;
            static inline SFXAllocator* GetInstance() {
                return &RESOLVE_STATIC_VARIABLE(instance);
            }

            void Setup(SupportFX::LightFieldDescription& desc);
        };
    
        uint32_t vertexShaderCount;
        void* vertexShaderData[128];
        size_t vertexShaderSizes[128];
        uint32_t pixelShaderCount;
        void* pixelShaderData[128];
        size_t pixelShaderSizes[128];
        uint32_t computeShaderCount;
        void* computeShaderData[128];
        size_t computeShaderSizes[128];
        VertexShader* vertexShaders[128];
        PixelShader* pixelShaders[128];
        ComputeShader* computeShaders[128];
        void* unk6a[5];
        RenderingDevice* renderingDevice;
        VertexShader* commonVertexShader;
        VertexShader* zPrepassSimpleVertexShader;
        VertexShader* zPrepassSimplePTVertexShader;
        PixelShader* commonPixelShader;
        PixelShader* unkPixelShader; // not filled in? zPrepassSimplePixelShader?
        PixelShader* zPrepassSimplePTPixelShader;
        ShaderObject* commonShaderObject;
        ShaderObject* zPrepassSimpleShaderObject;
        ShaderObject* zPrepassSimplePTShaderObject;
        ShaderListInfo* shaderListInfo;
        DisplaySwapDevice* swapDevice;
        intrusive_ptr<RenderManager> renderManager;
        intrusive_ptr<PBRModelInstanceRenderer> modelInstanceRenderer;
        void* unk10_4;
        intrusive_ptr<ParameterValueObject> globalParameters;
        csl::ut::MoveArray<intrusive_ptr<SceneContextManager>> sceneContextManagers;
        float worldScale;
        Texture* textures[13];
        void* unk13_0;
        void* unk13_1;
        CopyColor* copyColor;
        CopyColor* copyDepthColor;
        RenderTarget* renderTarget;
        Texture* renderTargetTextureView;
        csl::ut::MoveArray<void*> unk13_6;
        uint64_t unk13b[7];
        uint64_t unk14;
        float deltaTime;
        float totalTime[4];
        uint32_t frameCount;
        uint32_t unk16b;
        uint8_t unk17;
        uint32_t unk18;
        FillMode fillMode;
        CaptureIBLListener* captureIBLListener;
        FxPerformanceCounter* performanceCounter;
        uint64_t unk21;
        uint64_t unk22;
        int32_t unk23;
        uint64_t unk24;
        intrusive_ptr<RenderingDeviceContext> renderingDeviceContextTLS;
        intrusive_ptr<RenderingDeviceContext> renderingDeviceContext;
        intrusive_ptr<RenderingContextManager> renderingContextManager;
        intrusive_ptr<PrimitiveRenderer> primitiveRenderer;
        SupportFX* unkBackRef;
        uint32_t unk29;
        void* unk30;
        void* unk31;

        bool CreateDevice(unsigned int resX, unsigned int resY, void* unkParam3, intrusive_ptr<RenderingDevice>& renderingDevice, bool unkParam4, void* unkParam5, void* unkParam6);
        void CreateRenderManager(unsigned int resX, unsigned int resY, unsigned int renderResX, unsigned int renderResY, intrusive_ptr<RenderingDevice>& renderingDevice, void* unkParam5);
        RenderingDevice* GetRenderingDevice() const;
        // Gets Immediate context
        RenderingDeviceContext* GetRenderingContext() const;
        // Gets Deferred context
        RenderingDeviceContext* GetRenderingContext2() const;
        RenderingContextManager* GetRenderingContextManager() const;
        RenderManager* GetRenderManager() const;
        SceneContextManager* GetSceneContextManager(const char* name) const;
        SceneContextManager* GetSceneContextManager(const CNameIDObject* name) const;
        VertexShader* GetVertexShader(unsigned int idx) const;
        PixelShader* GetPixelShader(unsigned int idx) const;
        ComputeShader* GetComputeShader(unsigned int idx) const;
        void AddSceneContextManager(SceneContextManager* sceneContextManager);
        void SetWorldScale(float scale);
        void AddRenderUnit(RenderUnit* unit);
        RenderTarget* GetRenderTarget(unsigned int index) const;
        Texture* GetRenderTargetView(unsigned int index) const;
        RenderTarget* GetDepthStencil(unsigned int index) const;
        Texture* GetDepthStencilView(unsigned int index) const;
        void GetRenderTargetDimensions(unsigned int index, unsigned int& width, unsigned int& height) const;
        VertexShader* GetVertexShader(void* data, size_t size);
        PixelShader* GetPixelShader(void* data, size_t size);
        ComputeShader* GetComputeShader(void* data, size_t size);
        void DestroyRenderUnit(const char* name);
        PBRModelInstance* CreatePBRModelInstance(Model* model, const PBRModelCreationInfo& info);
        static Rectangle GetRenderTargetRect(RenderTargetManager* manager, const RenderTargetReference& rtRef, SupportFX::FxViewport& viewport);

        void SetListener(CaptureIBLListener* listener);
        void SetupLightField(LightFieldDescription& desc, const char* sceneName);

        static SupportFX* instance;

        SupportFX();
        virtual ~SupportFX();
        virtual void OnCreateRenderManager(RenderManager* renderManager) = 0;
        virtual bool Render(const FxRenderParam& renderParam, RenderTarget* renderTarget) { return true; }
        virtual bool Present();
        virtual void UnkFunc4(float unkParam1, uint32_t numCameras, FxCamera** cameras);
    };

    class SupportFXAll : public SupportFX {
    public:
        void* unk101;
        void* unk102;
        void* unk103;
        uint64_t unk104;
        uint64_t unk105;
        uint64_t unk106;
        uint8_t unk109;
        csl::ut::LinkList<RenderUnit> renderUnits;
        const char* mainSceneName;
        csl::ut::MoveArray<void*> unk112;
        float globalUserParams[4][4];
        needle::Texture* unk114[3];

        SupportFXAll();

        virtual void OnCreateRenderManager(RenderManager* renderManager) override;
        virtual bool Render(const FxRenderParam& renderParam, RenderTarget* renderTarget) override;
        virtual bool Present() override;
        virtual void UnkFunc4(float unkParam1, uint32_t numCameras, FxCamera** cameras) override;

        RenderTextureHandle* CreateRenderTextureHandle(const RenderTextureCreateArgs& createArgs);
        RenderUnit* GetRenderUnitByName(const char* name) const;
        RenderUnit* GetRenderUnitByName(const CNameIDObject* name) const;
    };
}
