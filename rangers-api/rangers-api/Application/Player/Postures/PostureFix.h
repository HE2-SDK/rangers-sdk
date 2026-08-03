#pragma once

namespace app::player {
	class PostureFix : public PlayerPosture {
	public:
		struct Description {
			char byte20;
			char byte21;
		};
		
		char byte20;
		char byte21;
	
		virtual unsigned int GetNameHash() const override;
        virtual unsigned int UnkFunc2() override { return 0; }
        virtual void Enter() override;
        virtual void Update(float deltaTime, const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void UnkFunc6() override;
		
		void Setup(const Description& desc);
		
		PostureFix(csl::fnd::IAllocator* allocator);
	};
}
