#pragma once

namespace app::game{
    class GOCParamBlackboard : public hh::game::GOComponent {
    public:
        struct Parameter {
            unsigned int nameHash;
            int64_t value;
        };

        hh::fnd::Handle<hh::game::GOComponent> gocomponent; // bossgiantstate::walkingbase uses this for PathComponent
        bool hasGOC;
        int unk2;
        char unk3;
        csl::ut::MoveArray<Parameter> parameters;

		virtual void* GetRuntimeTypeInfo() const;

        GOCOMPONENT_CLASS_DECLARATION(GOCParamBlackboard)
    };
}
