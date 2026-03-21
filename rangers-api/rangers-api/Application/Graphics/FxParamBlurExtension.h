#pragma once

namespace app::gfx {
    class FxParamBlurExtension : public FxParamExtension, public hh::game::GameManagerListener {
    public:
        DEFAULT_CREATE_FUNC(FxParamBlurExtension);

        virtual void* GetRuntimeTypeInfo() override;
        virtual void Initialize() override;
        virtual void Destroy() override;
        virtual void MessageProcessedCallback(hh::game::GameManager* gameManager, const hh::fnd::Message& msg) override;

        void SetBlur(unsigned int id, float duration);
        void RemoveBlur(unsigned int id);
    };
}
