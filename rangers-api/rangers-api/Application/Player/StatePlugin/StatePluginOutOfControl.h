#pragma once

namespace app::player {
    class StatePluginOutOfControl : public PlayerStatePlugin {
    public:
        static constexpr const char* name = "StatePluginOutOfControl";

        struct OutOfControlController {
            enum class Flags : unsigned int {
                RELEASE_BY_GROUND,
                UNK0,
                UNK1,
            };

            int nameHash;
            float unk;
            csl::ut::Bitset<Flags> flags;
        };

        enum class Flags : unsigned char {
            IS_OUT_OF_CONTROL
        };

        csl::ut::MoveArray<OutOfControlController> controllers;
        csl::ut::MoveArray<int64_t> qword48;
        csl::ut::Bitset<Flags> flags;
        char byte69;

        virtual unsigned int GetNameHash() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void Update(hh::fnd::UpdatingPhase phase, const float deltaTime) override;

        void UnkFunc1342(unsigned int nameHash, unsigned int unkParam1);

        StatePluginOutOfControl(csl::fnd::IAllocator* allocator);
    };
}
