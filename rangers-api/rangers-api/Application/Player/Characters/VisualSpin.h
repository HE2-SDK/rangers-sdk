#pragma once

namespace app::player {
	class VisualSpin : public PlayerVisual {
	public:
		virtual bool IsSuper() = 0;
		virtual void VS_UnkFunc1(char a2) {};
	
		VisualSpin(csl::fnd::IAllocator* allocator, hh::game::GameObject* gameObject, ComponentCollection* componentCollection);
	};
}
