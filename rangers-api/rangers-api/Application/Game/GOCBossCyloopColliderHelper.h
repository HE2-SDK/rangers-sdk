#pragma once

namespace app::game{
    class GOCBossCyloopColliderHelper : public hh::game::GOComponent {
    public:
        struct Unk0{
            hh::fnd::Handle<hh::game::GOComponent> unk0;
            int unk1;
            hh::fnd::Reference<hh::gfx::ModelNodeHFrame> hFrame;
            hh::fnd::Handle<hh::game::GOComponent> unk2;
        };

        csl::ut::MoveArray<Unk0> unks;
        hh::fnd::Handle<hh::game::GOComponent> unk0;

        virtual void* GetRuntimeTypeInfo() const override;
        // sub_1405E0A80

        GOCOMPONENT_CLASS_DECLARATION(GOCBossCyloopColliderHelper)
    };
}
