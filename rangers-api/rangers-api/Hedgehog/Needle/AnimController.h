#pragma once

namespace hh::needle {
    class AnimController {
    public:
        uint8_t unk1;
        bool isDirty;
        float localTime;
        float start;
        float end;
        float fps;
        float speed;
        float unk6;
        uint32_t unk7;

        AnimController();
        virtual ~AnimController() = default;
        virtual void UnkFunc1(float unkParam);
        virtual void SetDirty();

        float GetLocalTime() const;
        void SetLocalTime(float time);
        float GetSpeed() const;
        void SetSpeed(float speed);
        void SetStart(float start);
        void SetEnd(float end);
        inline void SetFps(float fps) { this->fps = fps; }
        float GetStart() const;
        float GetEnd() const;
        void SetAnimationParameters(float start, float end, float fps);
    };
}
