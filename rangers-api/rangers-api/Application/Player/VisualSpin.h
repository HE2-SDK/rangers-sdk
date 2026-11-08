#pragma once

namespace app::player {
    class VisualSpin : public PlayerVisual {
    public:
        VisualSpin(csl::fnd::IAllocator* allocator, hh::game::GameObject* gameObject, ComponentCollection* componentCollection);

		virtual bool IsSuper() const = 0;
		virtual void SetIsSuper(bool enabled) {};
    };
}