#pragma once

namespace hh::needle {
    class NeedleUniqueBlob : public TNeedleRefcountUniqueObjectBase<NeedleRefcountObject> {
    public:
        size_t size;

        static NeedleUniqueBlob* Create(const void* data, size_t size);
    };
}
