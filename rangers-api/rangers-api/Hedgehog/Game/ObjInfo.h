#pragma once

#define OBJINFO_CLASS_DECLARATION_BASE(ClassName) public:\
		static const hh::game::ObjInfoClass objInfoClass;\
		ClassName(csl::fnd::IAllocator* allocator);\
		static hh::game::ObjInfo* Create(csl::fnd::IAllocator* allocator);\

#define OBJINFO_CLASS_DECLARATION(ClassName) OBJINFO_CLASS_DECLARATION_BASE(ClassName)\
	public:\
		static const hh::game::ObjInfoClass* GetClass();

#define OBJINFO_CLASS_DECLARATION_INLINE(ClassName) OBJINFO_CLASS_DECLARATION_BASE(ClassName)\
	public:\
		static inline const hh::game::ObjInfoClass* GetClass() {\
			return &RESOLVE_STATIC_VARIABLE(objInfoClass);\
		}

namespace hh::game {
    class ObjInfo;
    class ObjInfoContainer;

    class ObjInfoClass {
    public:
        const char *name;
        ObjInfo* (*instantiator)(csl::fnd::IAllocator* pAllocator);
    };

    class ObjInfo : public fnd::ReferencedObject {
    public:
        enum class Flag {
            LOADED = 0,
            INITIALIZED = 1,
        };

        csl::ut::Bitset<Flag> flags;
        fnd::Reference<fnd::ResourceLoader> resourceLoader;
        fnd::Reference<LevelLoader> levelLoader;
        GameManager* gameManager;

        ObjInfo(csl::fnd::IAllocator* pAllocator);
        virtual void Load() {}
        virtual void Initialize(GameManager* gameManager) {}
        virtual void Finalize() {}
        virtual const char* GetInfoName();
        virtual void RegistCallback(ObjInfoContainer* container) {}
    };
}
