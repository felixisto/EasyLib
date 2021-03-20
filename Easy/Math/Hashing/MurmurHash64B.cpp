
#include "MurmurHash64B.h"

using namespace easy;

const MurmurHash64B& MurmurHash64B::global() {
    static MurmurHash64B hasher;
    return hasher;
}

MurmurHash64B::MurmurHash64B() : seed(1) {

}

MurmurHash64B::MurmurHash64B(int seed) : seed(seed) {

}

ubig MurmurHash64B::combine(ubig a, ubig b) const {
    return a + b;
}

ubig MurmurHash64B::hash(const void* value) const {
    return (ubig)value;
}

ubig MurmurHash64B::hash(bool value) const {
    return (ubig)value;
}

ubig MurmurHash64B::hash(byte value) const {
    return (ubig)value;
}

ubig MurmurHash64B::hash(short value) const {
    return (ubig)value;
}

ubig MurmurHash64B::hash(ushort value) const {
    return (ubig)value;
}

ubig MurmurHash64B::hash(integer value) const {
    return (ubig)value;
}

ubig MurmurHash64B::hash(uinteger value) const {
    return (ubig)value;
}

ubig MurmurHash64B::hash(big value) const {
    return (ubig)value;
}

ubig MurmurHash64B::hash(ubig value) const {
    return (ubig)value;
}

ubig MurmurHash64B::hash(float value) const {
    return (ubig)value;
}

ubig MurmurHash64B::hash(double value) const {
    return (ubig)value;
}

ubig MurmurHash64B::hash(const CString& value) const {
    integer length = value.length();
    cstring buffer = value.buffer();

    if (length == 0) {
        return 0;
    }

    if (length > 512) {
        return 1;
    }

    const unsigned int m = 0x5bd1e995;
    const int r = 24;

    unsigned int h1 = seed ^ length;
    unsigned int h2 = 0;

    const unsigned int* data = (const unsigned int*)buffer;

    while (length >= 8) {
        unsigned int k1 = *data++;
        k1 *= m; k1 ^= k1 >> r; k1 *= m;
        h1 *= m; h1 ^= k1;
        length -= 4;

        unsigned int k2 = *data++;
        k2 *= m; k2 ^= k2 >> r; k2 *= m;
        h2 *= m; h2 ^= k2;
        length -= 4;
    }

    if (length >= 4) {
        unsigned int k1 = *data++;
        k1 *= m; k1 ^= k1 >> r; k1 *= m;
        h1 *= m; h1 ^= k1;
        length -= 4;
    }

    switch (length) {
    case 3: h2 ^= ((unsigned char*)data)[2] << 16;
    case 2: h2 ^= ((unsigned char*)data)[1] << 8;
    case 1: h2 ^= ((unsigned char*)data)[0];
        h2 *= m;
    };

    h1 ^= h2 >> 18; h1 *= m;
    h2 ^= h1 >> 22; h2 *= m;
    h1 ^= h2 >> 17; h1 *= m;
    h2 ^= h1 >> 19; h2 *= m;

    ubig h = h1;
    h = (h << 32) | h2;
    return h;
}

ubig MurmurHash64B::hash(const Byte& value) const {
    return value.value;
}

ubig MurmurHash64B::hash(const Short& value) const {
    return value.value;
}

ubig MurmurHash64B::hash(const UShort& value) const {
    return value.value;
}

ubig MurmurHash64B::hash(const Integer& value) const {
    return value.value;
}

ubig MurmurHash64B::hash(const UInteger& value) const {
    return value.value;
}

ubig MurmurHash64B::hash(const Big& value) const {
    return value.value;
}

ubig MurmurHash64B::hash(const UBig& value) const {
    return value.value;
}

ubig MurmurHash64B::hash(const Real& value) const {
    return (ubig)value.value;
}

ubig MurmurHash64B::hash(const Hashable& value) const {
    return value.hashValue();
}
