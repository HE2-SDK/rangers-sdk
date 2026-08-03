#pragma once

namespace Cyan {
    class AnimCtrl {
    public:
        struct CurveStatus {
            int unk0;
            int unk1;
            int unk2;
            float value0;
            int unk3;
            int unk4;
            int unk5;
            float value1;
            int unk7;
            int unk8;
            int unk9;
            float value2;
        };

        struct CreateParam {
            enum class RandomSetType {
                UNK0 = 1,
                UNK1,
                UNK2,
                UNK3,
                UNK4,
                UNK5,
            };

            System::RandomTable* randomTable;
            System::Random* random;
            char flags;
            float fps;
            float currentTime;
            float unk2b;
            void* colorSet;
            RandomSetType randomSetType;
            int32_t unk4;
        };

        Resource::AnimationParam* animParam;
        float duration;
        float dwordC;
        int dword10;
        int loopCount;
        float dword18;
        CurveStatus curves[4];
        char gap1c[4];
        CreateParam createParam;
        short word110;
        int64_t qword118;
        int64_t qword120;

        AnimCtrl(const Resource::AnimationParam* animParam, const CreateParam& createParam);

        void InitAnimation(const CreateParam& createParam);
        void Update(float time);
        float GetValue(int idx) const;
        unsigned int GetValues(float* values, int count) const;
        float GetKeyValue(const CurveStatus* curveStatus, int key);
        unsigned short GetCurveNum() const;
        void CalcKeyValue(float unk, CurveStatus* curveStatus);
        void* Interpolation(const CurveStatus* curveStatus, int unk0, int unk1, float unk2, float unk3);
        void SetTime(float time);
    };
}
