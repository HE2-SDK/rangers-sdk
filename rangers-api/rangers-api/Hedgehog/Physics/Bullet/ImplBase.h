#pragma once

namespace hh::physics::bullet{
    class ImplBase {
    public:
        virtual void Init() = 0;
        virtual void UnkFunc1(int64_t a2) = 0;
        virtual void* GetRuntimeTypeInfo() const = 0;
        virtual ~ImplBase() = 0;
    };
}
