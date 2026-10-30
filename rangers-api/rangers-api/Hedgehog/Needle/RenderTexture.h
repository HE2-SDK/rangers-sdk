#pragma once

namespace hh::needle {
    class FxRenderTextureCamera : public FxCamera, public NeedleRefcountObject {
    public:
        csl::math::Vector3 position;
        csl::math::Matrix44 viewMatrix;
        csl::math::Matrix44 projMatrix;

        FxRenderTextureCamera();

        virtual csl::math::Vector3 GetEyePos() const override;
        virtual void GetEyePosF(float* eyePos) const override;
        virtual csl::math::Vector3 GetLookAtPos() const override;
        virtual void GetLookAtPosF(float* lookAtPos) const override {}
        virtual csl::math::Matrix44 GetViewMatrix() const override;
        virtual void GetViewMatrixF(float* viewMatrix) const override;
        virtual csl::math::Matrix44 GetProjectionMatrix() const override;
        virtual void GetProjectionMatrixF(float* projectionMatrix) const override;
    };

    struct RenderTextureCreateArgs {
        enum Flag {
            UNK0 = 1,
            RESOLVE = 2, // decides some even/odd logic in setrenderdimensions... backbuffer?
            UNK2 = 4,
            UNK3 = 8,
            COPIED = 0x10,
        };

        struct TextureSettings {
            SurfaceFormat format{};
            unsigned int mipLevels{};
        };

        unsigned int width;
        unsigned int height;
        Flag flags;
        unsigned int clearedTextureCount;
        TextureSettings* textureSettings;
        csl::fnd::IAllocator* allocator;
        RenderTexturePipeline* pipeline;
        const char* name;
        const char* sceneName;
        bool autoCreatePipeline;
    };

    class RenderTextureHandle : public RenderUnit {
    public:
        enum RenderStage : unsigned int {
            UNK0,
            UNK1,
            UNK2,
            UNK3,
            UNK4,
            UNK5,
            UNK6,
            UNK7,
            UNK8,
            UNK9,
        };

        bool destroySceneContextManager;
        intrusive_ptr<RenderTarget> renderTargets1[4];
        intrusive_ptr<Texture> renderTargetTextures1[4];
        intrusive_ptr<RenderTarget> renderTargets2[4];
        intrusive_ptr<Texture> renderTargetTextures2[4];
        intrusive_ptr<DepthStencil> depthStencil;
        intrusive_ptr<Texture> depthStencilTexture;
        intrusive_ptr<RenderTarget> renderTarget3;
        intrusive_ptr<Texture> renderTargetTexture3;
        unsigned int width;
        unsigned int height;
        csl::math::Vector4 clearColor;
        unsigned int clearedTextureCount;
        RenderTextureCreateArgs::Flag flags;
        intrusive_ptr<FxRenderTextureCamera> camera;
        uint32_t unk115;
        int unk116;
        int unk117;
        uint64_t unk118;
        uint64_t unk119;
        uint64_t unk120;
        uint64_t unk121;

        RenderTextureHandle(const RenderTextureCreateArgs& createArgs, SupportFXAll* supportFX, RenderManager* renderManager);
        RenderTextureHandle(const RenderTextureCreateArgs& createArgs, SupportFXAll* supportFX);
        
        virtual bool IsEnabled(const RenderInfo& renderInfo) override;
        virtual void SetRenderDimensions(const RenderInfo& renderInfo) override;
        virtual void UnkFunc5() override;
        virtual void LoadRenderParams(const RenderInfo& renderInfo) override;

        Renderable* GetRenderable(RenderStage renderStage) const;
        void SetCameraParameter(const csl::math::Matrix34& viewMatrix, const csl::math::Matrix44& projectionMatrix);
        void SetRenderResolution(unsigned int width, unsigned int height);
        void ChangePipeline(RenderingPipeline* pipeline);
        bool IsFlagSet(RenderTextureCreateArgs::Flag flag) const;
        Texture* GetTexture(unsigned int id) const;
        Texture* GetDepthStencilTexture() const;
        unsigned int GetClearedTextureCount() const;
        intrusive_ptr<RenderTarget>* GetRenderTarget(unsigned int idx) const;
        void Resolve(RenderingDeviceContext* ctx);
    };
}
