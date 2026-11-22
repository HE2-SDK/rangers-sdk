#pragma once

namespace app::player {
    class StatePluginAirTrick : public PlayerStatePlugin {
    public:
		static constexpr const char* name = "StatePluginAirTrick";

		hh::snd::SoundHandle soundHandle{};
		float trickingTime{};
		float airTrickHeight{};
		int direction{ -1 };
		int trickIndex{};
		bool sparkles{};
		bool byte3D{};
		uint8_t byte3E{ 1 };

        virtual unsigned int GetNameHash() const override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        DEFAULT_CREATE_FUNC(StatePluginAirTrick);
    };
}
