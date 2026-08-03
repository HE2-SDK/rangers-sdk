#pragma once

namespace hh::ut {
    namespace internal {
        class StateImpl;

        class StateDescImpl {
        public:
            typedef StateImpl* (*Instantiator)(csl::fnd::IAllocator* pAllocator);

            const char* name;
            Instantiator instantiator;
            int superState;

            StateDescImpl(const char* name, Instantiator instantiator, int superState);
        };
    };

    class StateDesc : public internal::StateDescImpl {
    public:
        StateDesc(const char* name, Instantiator instantiator, int superState)
            : StateDescImpl { name, instantiator, superState } {}

        virtual ~StateDesc() {}
    };

    struct StateDescID {
        unsigned int id;
        const StateDesc* desc;
    };
}
