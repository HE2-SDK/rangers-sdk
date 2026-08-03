#pragma once

namespace app::player {
	class StatePluginRecovery : public PlayerStatePlugin {
	public:
		static constexpr const char* name = "StatePluginRecovery";
		
		struct UnkStr {
			hh::fnd::HandleBase unk0;
			hh::fnd::WorldPosition unk2;
			char unk6a;
			char unk6b;
			char unk6c;
		};

	    csl::ut::CircularBuffer<hh::fnd::WorldPosition> playerWorldPositions;
	    csl::ut::MoveArray<UnkStr> qword58;
	    char flags;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        hh::fnd::WorldPosition GetRecoveryPosition(bool lastStandingPosition) const;

        StatePluginRecovery(csl::fnd::IAllocator* allocator);
	};
}
