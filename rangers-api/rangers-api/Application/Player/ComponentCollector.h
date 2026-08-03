#pragma once

namespace app::player {
    struct ComponentCollection;
    struct Component {
		enum class Flags : unsigned char {
			HIDDEN = 0,
			EFFECTS_VISIBLE = 1
		};
		
        ComponentCollection* collection;
        csl::ut::MoveArray<hh::fnd::Reference<hh::game::GOComponent>> components;
        hh::fnd::Reference<hh::gfx::GOCVisualModel> visual;
        hh::fnd::Reference<hh::anim::GOCAnimator> animator;
        csl::ut::MoveArray<hh::eff::EffectHandle> effects;
        csl::ut::Bitset<Flags> flags;

        void AddComponent(hh::game::GOComponent* component);
        void RemoveComponent(hh::game::GOComponent* component);
        void UpdateVisibility();
		void SetEffectVisibility(bool visible);
		void SetHidden(bool hidden, bool forceUpdate);
    };

	class ComponentHolderListener {
	public:
		virtual void CHL_UnkFunc0(ComponentCollection* compCollection) = 0;
	};

    class ComponentCollector;
    struct ComponentCollection {
        enum class Flag {
            UNK0,
            VISIBLE,
        };

        csl::ut::MoveArray<Component> components;
        ComponentCollector* componentCollector;
        ComponentHolderListener* listener;
        csl::ut::Bitset<Flag> flags;

        ComponentCollection();
        void Initialize(hh::game::GameObject* gameObject, unsigned int componentCount);
        Component& GetComponent(int id);
        hh::fnd::HFrame* GetFrame() const;
        void SetVisibility(bool visible);
        unsigned int GetSize() const;
    };
	
    class GOCPlayerVisual;
    class ComponentCollector : public hh::fnd::ReferencedObject {
    public:
        hh::game::GameObject* gameObject;
        GOCPlayerVisual* gocPlayerVisual;
        ComponentCollection componentCollections[4];
        hh::fnd::Reference<hh::fnd::HFrame> frame;
        int currentPlayerVisual;
        int unk3;
        bool unk4;

        ComponentCollector(csl::fnd::IAllocator* allocator, hh::game::GameObject* gameObject, GOCPlayerVisual* gocPlayerVisual);
        void AttachFrames();
        void SetCurrentPlayerVisual(int id, bool unk4Param);
    };
}
