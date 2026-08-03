#pragma once

namespace app::player {
    class GOCPlayerPath : public hh::game::GOComponent {
    public:
        struct UnkStr {
            hh::fnd::Handle<hh::path::PathComponent> pathComponent;
            int dword4;
            int dword8;
        };

        UnkStr qword80[6];

		virtual void* GetRuntimeTypeInfo() const override;

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerPath);
    };
}
