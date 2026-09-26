#pragma once

namespace app::gfx {
    class FxParamBlurExtension : public FxParamExtension, public hh::game::GameManagerListener {
    public:
        enum class BlurInterpolatorType : unsigned int {
            BOOST,
            BOOST_ON_CYLOOP,
            BOOST_ON_STRIDER,
            KNIGHT_FC,
            SIDE_VIEW,
            OPTION  
        };

        FxParamBlurExtension(csl::fnd::IAllocator* allocator);

        virtual void* GetRuntimeTypeInfo() override;
        virtual void Initialize() override;
        virtual void Destroy() override;

        virtual void MessageProcessedCallback(hh::game::GameManager* gameManager, const hh::fnd::Message& msg) override;

        void RemoveBlurInterpolator(BlurInterpolatorType type, float interpTime);
    };
}
