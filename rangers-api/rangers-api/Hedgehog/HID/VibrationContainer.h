#pragma once

namespace hh::hid{
    class VibrationContainer : public fnd::ReferencedObject{
    public:
        class VibrationMarge : public VibrationDataContainer{
        public:
        };

        struct VibrationObj{
            hh::hid::VibrationContainer* container;
            int handle;

            inline VibrationObj() : container{ nullptr }, handle{ 0 } {}
            void Initialize();
            bool NotExists();
            void UnkFunc1();
        };

        enum class VibrationType : unsigned int {
            ONESHOT,
            ALWAYS,
            AUTO
        };

        GamepadSteam* gamepad;
        int dataContainerAmount;
        short flags;
        csl::ut::MoveArray<VibrationDataContainer*> dataContainers;
        csl::ut::PointerMap<int, VibrationDataContainer*> hashDataContainers;
        csl::ut::MoveArray<void*> unkArray1;
        void* unk1;
        void* unk2;
        VibrationMarge* marge;

        VibrationContainer(csl::fnd::IAllocator* allocator, Gamepad* gamepad);

        void PlayVibration(const char* vibrationName, VibrationType vibrationType, VibrationContainer::VibrationObj* obj);
        bool NotExists(int handle);
    };
}
