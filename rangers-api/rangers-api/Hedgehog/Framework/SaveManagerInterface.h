#pragma once

namespace hh::fw {
    class SaveManagerInterface : public fnd::ReferencedObject, public fnd::user::UserInfoEventListener {
    public:
        class Impl : public fnd::ReferencedObject {
        public:
            SaveManagerInterface* saveInterface;

            Impl(csl::fnd::IAllocator* allocator, SaveManagerInterface* saveInterface);
        };

        uint32_t dword20;
        uint32_t dword24;
        const char* saveFolderFilepath;
        uint8_t byte30;
        uint8_t byte31;
        csl::ut::MoveArray<void*> unk38;
        csl::ut::MoveArray<void*> unk58;
        uint16_t flags;
        Impl* implementation;
        uint64_t jobImplementation;

        SaveManagerInterface(csl::fnd::IAllocator* allocator);

        virtual void UIEL_UnkFunc1() override;
    };
}
