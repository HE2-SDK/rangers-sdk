#pragma once

namespace hh::fnd {
    class ResourceLoaderManager : public hh::fnd::BaseObject, public csl::fnd::Singleton<ResourceLoaderManager> {
    public:
        csl::ut::MoveArray<int64_t> unk0;
        csl::ut::MoveArray<int64_t> unk1;
        csl::ut::MoveArray<int64_t> unk2;
        csl::ut::VariableString unk3;
        csl::fnd::Mutex mutex;

        void GetLocaleName(csl::ut::String& ret);
        static ResourceLoaderManager* Create(csl::fnd::IAllocator* allocator);
    };
}
