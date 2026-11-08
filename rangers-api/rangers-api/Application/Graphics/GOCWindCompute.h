#pragma once

namespace app::gfx {
    class GOCWindCompute : public hh::game::GOComponent {
    public:
        struct Unk1 {
            uint8_t unk1;
            uint64_t unk2;
            csl::math::Vector4 unk3;
            uint32_t unk4;
            float unk5;
            float unk6;
            float unk7;
        };

        uint64_t qword80;
        uint64_t qword88;
        csl::ut::MoveArray<void*> unk90;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void AddUnk1(unsigned int nameHash, const Unk1& unk1);

        GOCOMPONENT_CLASS_DECLARATION(GOCWindCompute)
    };
}
