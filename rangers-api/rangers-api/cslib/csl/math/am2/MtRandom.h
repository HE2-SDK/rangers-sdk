#pragma once

namespace csl::math {
    namespace am2 {
        class MtRandom {
        public:
            unsigned int seed;
            unsigned int state[0x270];

            virtual ~MtRandom();

            void Init(unsigned int seed);
            unsigned int Rand();
        };
    }

    struct Random {
        am2::MtRandom mtRandom;

        Random();
        Random(unsigned long long seed);

        float GetFloat() const;
        unsigned int GetUint32() {
            return mtRandom.Rand();
        }
        unsigned int GetUint32(unsigned int maxValue) const;
        unsigned int GetUint32(unsigned int minValue, unsigned int maxValue) const;
    };
}
