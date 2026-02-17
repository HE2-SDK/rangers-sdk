#pragma once

namespace app::player {
    class GOCPlayerPath : public hh::game::GOComponent {
    public:
        struct Unk1 {
            uint32_t unk1;
            uint32_t unk2;
            uint32_t unk3;
        };
        
        Unk1 unk101[6];

		virtual void* GetRuntimeTypeInfo() const override;

        GOCOMPONENT_CLASS_DECLARATION(GOCPlayerPath)
    };
}
