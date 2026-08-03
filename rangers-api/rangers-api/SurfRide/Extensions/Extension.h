#pragma once

namespace SurfRide {
    class Extension : public ReferencedObject {
    public:
        virtual void* GetRuntimeTypeInfo() const {}
    };
}
