#pragma once

namespace app::player {
	class PostureStop : public PlayerPosture {
	public:
		float speed;
		float dword24;
        bool byte28;
        bool byte29;
        bool byte2A;
	
		virtual unsigned int GetNameHash() const override;
        virtual unsigned int UnkFunc2() override { return 0; }
        virtual void Enter() override;
        virtual void Update(float deltaTime, const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void UnkFunc6() override;
		
		PostureStop(csl::fnd::IAllocator* allocator);
	};
}
