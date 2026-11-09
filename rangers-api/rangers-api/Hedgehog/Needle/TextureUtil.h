#pragma once

namespace hh::needle {
    class TextureUtil : public NeedleRefcountObject {
    public:
        class Impl : public NeedleRefcountObject {
        public:
            struct UnkStr {
                int64_t qword0;
                int64_t qword8;
                int64_t qword10;
            };

            int64_t qword10;
            int dword18;
            UnkStr qword20[20];
            int64_t qword200;
            int64_t qword208;
            int64_t qword210;
            int64_t qword218;
            int dword220;
        };

        intrusive_ptr<Impl> implementation;

        TextureUtil();
    };
}
