#pragma once

#include "DataSize.h"

using namespace easy;

// # DataSize

DataSize DataSize::zero() {
    return DataSize(0);
}

DataSize DataSize::fromBytes(ubig bytes) {
    return DataSize(bytes);
}

DataSize DataSize::fromKB(real KB) {
    ubig bytes = (ubig)KB;
    bytes *= 1024;
    return DataSize(bytes);
}

DataSize DataSize::fromMB(real MB) {
    ubig bytes = (ubig)MB;
    bytes *= 1024;
    bytes *= 1024;
    return DataSize(bytes);
}

DataSize DataSize::fromGB(real GB) {
    ubig bytes = (ubig)GB;
    bytes *= 1024;
    bytes *= 1024;
    bytes *= 1024;
    return DataSize(bytes);
}

DataSize DataSize::fromTB(real TB) {
    ubig bytes = (ubig)TB;
    bytes *= 1024;
    bytes *= 1024;
    bytes *= 1024;
    bytes *= 1024;
    return DataSize(bytes);
}

DataSize DataSize::fromPB(real PB) {
    ubig bytes = (ubig)PB;
    bytes *= 1024;
    bytes *= 1024;
    bytes *= 1024;
    bytes *= 1024;
    bytes *= 1024;
    return DataSize(bytes);
}

DataSize::DataSize(ubig bytes) : _bytes(bytes) {

}

DataSize::DataSize(const DataSize& other) : _bytes(other._bytes) {

}

bool DataSize::operator==(const DataSize& other) const {
    return _bytes == other._bytes;
}

bool DataSize::operator<(const DataSize& other) const {
    return _bytes < other._bytes;
}

bool DataSize::operator<=(const DataSize& other) const {
    return _bytes <= other._bytes;
}

bool DataSize::operator>(const DataSize& other) const {
    return _bytes > other._bytes;
}

bool DataSize::operator>=(const DataSize& other) const {
    return _bytes >= other._bytes;
}

DataSize& DataSize::operator=(const DataSize& other) {
    _bytes = other._bytes;
    return *this;
}

DataSize DataSize::operator+(const DataSize& other) const {
    return _bytes + other._bytes;
}

DataSize DataSize::operator-(const DataSize& other) const {
    return _bytes - other._bytes;
}

DataSize DataSize::operator*(const DataSize& other) const {
    return _bytes * other._bytes;
}

DataSize DataSize::operator/(const DataSize& other) const {
    return _bytes / other._bytes;
}

DataSize& DataSize::operator+=(const DataSize& other) {
    _bytes += other._bytes;
    return *this;
}

DataSize& DataSize::operator-=(const DataSize& other) {
    _bytes -= other._bytes;
    return *this;
}

DataSize& DataSize::operator++() {
    // Prefix ++
    _bytes++;
    return *this;
}

DataSize DataSize::operator++(int postFix) {
    // Postfix ++
    auto old = *this;
    _bytes++;
    return old;
}

ubig DataSize::inBytes() const {
    return _bytes;
}

real DataSize::inKB() const {
    real bytes = inBytes();
    return bytes / 1024.0;
}

real DataSize::inMB() const {
    return inKB() / 1024.0;
}

real DataSize::inGB() const {
    return inMB() / 1024.0;
}

real DataSize::inTB() const {
    return inGB() / 1024.0;
}

real DataSize::inPB() const {
    return inTB() / 1024.0;
}
