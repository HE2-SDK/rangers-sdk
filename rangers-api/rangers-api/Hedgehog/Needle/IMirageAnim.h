#pragma once

namespace hh::needle{
    template<typename T, typename U>
    class IMirageAnim : public NeedleRefcountObject {
    public:
        virtual bool GetResult(T* idx, U* ret) = 0;
        virtual void* UnkFunc1() = 0;
        virtual int UnkFunc2() = 0;
    };

    template<typename T, typename U>
    class MirageAnimController : public IMirageAnim<T, U> {
    public:
        AnimController animController;

        virtual void* UnkFunc1() override;
        virtual int UnkFunc2() override;
    };

    template<typename T>
    class AnimBlender : public IMirageAnim<typename T::ID, typename T::Result> {
    public:
        unsigned int animationCount;
        T** controls;

        virtual bool GetResult(T::ID* idx, T::Result* ret) override;
        virtual void* UnkFunc1() override;
        virtual int UnkFunc2() override;
    };
}
