#pragma once

namespace hh::hid {
    class Vibration : public InputDevice {
    public:
        struct RumbleData {
            float low;
            float high;
        };

        Vibration(csl::fnd::IAllocator* pAllocator);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual unsigned int GetDeviceId() const override;
        virtual void UnkFunc8() {}
        virtual unsigned int UnkFunc9();
        virtual bool SetController(unsigned int unk0, unsigned int unk1, unsigned int controllerIndex);
        virtual void StartRumble(RumbleData& rumble) {}
        virtual void SetRumble(bool pause) {}
        virtual void StopRumble() {}
    };
}
