#pragma once

namespace app::player {
    class StatePluginSpannerThrow : public PlayerStatePlugin {
    public:
		static constexpr const char* name = "StatePluginSpannerThrow";
        
        float dword28;
        float dword2C;
        int dword30;
        int dword34;
        hh::eff::EffectHandle dword38;
        short word48;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        StatePluginSpannerThrow(csl::fnd::IAllocator* allocator);
    };
}
