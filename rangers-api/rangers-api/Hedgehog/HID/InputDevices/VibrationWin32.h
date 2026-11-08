#pragma once

namespace hh::hid {
    class VibrationWin32 : public Vibration {
        int32_t unk101;
        uint32_t controllerIndex;
        unsigned short vibData[2]; // XINPUT_VIBRATION
    public:
        VibrationWin32(csl::fnd::IAllocator* pAllocator);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool SetController(unsigned int unk0,unsigned int unk1, unsigned int controllerIndex) override;
        virtual void StartRumble(RumbleData& rumble) override;
        virtual void SetRumble(bool pause) override;
        virtual void StopRumble() override;

        static VibrationWin32* CreateDevice(unsigned int deviceIndex, csl::fnd::IAllocator* pAllocator);
    };
}
