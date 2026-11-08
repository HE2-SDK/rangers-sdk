#pragma once

namespace csl::ut {
    template<unsigned int T>
    struct FixedString {
        char data[T];

        inline const char* c_str() const {
            return data;
        }

        inline char& operator[] (unsigned int i) {
			return data[i];
		}

        inline bool operator==(const FixedString<T>& other) const {
            return strcmp(other.data, data) == 0;
        }

        inline bool operator==(const char*& other) const {
            return strcmp(other, data) == 0;
        }

        inline FixedString<T>& operator=(const FixedString<T>& other) {
            if (this == &other)
                return *this;

            memcpy(data, other.data, T);
            return *this;
        }

        inline FixedString<T>& operator=(const char*& other) {
            memcpy(data, other, T);
            return *this;
        }
    };
}
