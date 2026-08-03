#pragma once
#include <ucsl/resources/vibration/v21.h>

namespace hh::hid{
    class VibrationData : public fnd::ReferencedObject {
    public:
        int dataIdx;
        int idx; //unsure @ 0x140F27686
        char vibrationDataId;
        float freq;
        float freqScale;
        int unk5;
        VibrationHapticPlayer* vibHapticPlayer;
    };

    class VibrationDataContainer : public fnd::ReferencedObject{
    public:
        struct Description{
            ucsl::resources::vibration::v21::Vibration* vibData;
            int dataIdx;
            bool looping;
            bool unk1;
            hh::hid::VibrationWin32* vibration;
            int gamepadUnk102;
        };

        enum class Flags : unsigned char{
            UNK0,
            UNK1,
            LOOPING,
            UNK2,
            UNK3,
            HAS_AUDIO
        };

        ucsl::resources::vibration::v21::Vibration* vibData;
        int dataIdx;
        float unk2;
        float maxPositionX;
        int unk4;
        csl::ut::MoveArray<VibrationData*> vibrationDatas;
        int unk6;
        int unk7;
        csl::ut::Bitset<Flags> flags;
        int unk9;
        float unk10;
        int unk11;
        VibrationData* vibrationDataType4;

        VibrationDataContainer(csl::fnd::IAllocator* allocator);

        void Initialize(Description& desc);
    };
}
