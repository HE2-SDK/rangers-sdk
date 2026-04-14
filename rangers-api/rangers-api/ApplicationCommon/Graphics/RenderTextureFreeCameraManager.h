#pragma once

namespace app_cmn::gfx{
    class RenderTextureFreeCameraManager : public hh::game::GameService {
    public:
        int64_t unk0;
        RenderTextureFreeCamera* camera;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void OnRemovedFromGame() override;

        GAMESERVICE_CLASS_DECLARATION(RenderTextureFreeCameraManager)
    };
}
