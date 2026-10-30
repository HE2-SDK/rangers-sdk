#pragma once

namespace csl::fnd{
    class Tick {
    public:
        int64_t time;

        void Initialize();
        void Sample();
        int64_t ToMiliseconds() const;
        int64_t ToMicroseconds() const;
    };
}
