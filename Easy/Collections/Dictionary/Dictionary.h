#pragma once

#include "../Array/List.h"
#include "../../Foundation/CString.h"
#include "../Enumeration/PairIterator.h"
#include "../../Formatters/StringFormatter.h"
#include <map>

namespace easy {
    template <typename Key, typename E>
    using DictionaryEnumeratable = MapEnumerable<Key, E>;

    template <typename Key, typename E>
    using DictionaryIterator = MapIterator<Key, E>;

    template <typename Key, typename E>
    using MutableDictionaryIterator = MutableMapIterator<Key, E>;

    /*
     * Maps keys to values. Ordered.
     *
     * A map cannot contain duplicate keys, but it may contain duplicate values.
     * 
     * Performance:
     * Access: -
     * Insertion: O(log n)
     * Erase: O(log n)
     * Find: O(log n)
     */
    template <typename Key, typename E>
    struct Dictionary: Collection<E>, StringRepresentable, Hashable, Copyable<Dictionary<Key, E>>, DictionaryEnumeratable<Key, E> {
    private:

        /// Map.
        std::map<Key, E> _map;

    public:
        Dictionary() {

        }

        Dictionary(const Dictionary<Key, E>& dictionary) {
            addAll(dictionary);
        }

        Dictionary(MapIterator<Key, E> it) {
            while (it.hasNext()) {
                auto& entry = it.get();
                insert(entry.first, entry.second);
                it++;
            }
        }

        virtual ~Dictionary() {
            // The static asserts are here, so that Dictionary can work with forward declarations
            static_assert(constraints::isEqualityComparable<Key>::value, "<Key> must support equality");
            static_assert(constraints::isLesserComparable<Key>::value, "<Key> must support lesser than comparison");
            static_assert(constraints::isTypeOf<Hashable, Key>::value, "<Key> must implement Hashable");
            static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
            static_assert(constraints::isTypeOf<StringRepresentable, E>::value, "<E> must implement StringRepresentable");
            static_assert(constraints::isTypeOf<Hashable, E>::value, "<E> must implement Hashable");

            removeAll();
        }

        // # Properties

        integer size() const {
            return _map.size();
        }

        // # Operators

        const E& operator[](const Key& key) const {
            return _map[key];
        }

        E& operator[](const Key& key) {
            return _map[key];
        }

        bool operator==(const Dictionary& other) const {
            return _map == other._map;
        }

        Dictionary& operator=(const Dictionary& other) {
            _map = other._map;
            return *this;
        }

        Dictionary operator+(const Dictionary& other) const {
            auto result = _map + other._map;
            return Dictionary(result);
        }

        Dictionary& operator+=(const Dictionary& other) {
            _map += other._map;
            return *this;
        }

        // # Query

        List<Key> keys() const {
            List<Key> result;

            for (auto it = _map.begin(); it != _map.end(); ++it)  {
                result.add(it->first);
            }

            return result;
        }

        List<E> values() const {
            List<E> result;

            for (auto it = _map.begin(); it != _map.end(); ++it) {
                result.add(it->second);
            }

            return result;
        }

        List<Key> keysForValue(const E& value) const {
            List<Key> result;

            for (auto it = _map.begin(); it != _map.end(); ++it) {
                if (it->second == value) {
                    result.add(it->first);
                }
            }

            return result;
        }

        bool containsKey(const Key& key) const {
            for (auto it = _map.begin(); it != _map.end(); ++it) {
                if (it->first == key) {
                    return true;
                }
            }
            return false;
        }

        bool containsValue(const E& value) const {
            for (auto it = _map.begin(); it != _map.end(); ++it) {
                if (it->second == value) {
                    return true;
                }
            }
            return false;
        }

        // # Modification

        void insert(const Key& key, const E& value) {
            _map[key] = value;
        }

        void addAll(const Dictionary<Key, E>& dictionary) {
            for (auto it = dictionary._map.begin(); it != dictionary._map.end(); ++it) {
                _map[it->first] = it->second;
            }
        }

        void removeValueFor(const Key& key) {
            _map.erase(key);
        }

        void removeAllValueOccurrences(const E& value) {
            auto keys = keysForValue(value);

            while (keys.size() > 0) {
                removeValueFor(keys.first());

                keys.removeFirst();
            }
        }

        void removeAll() {
            _map.clear();
        }

        // # StringRepresentable

        virtual CString stringRepresentableOfKey(const Key& key) const {
            return key.toString();
        }

        virtual CString stringRepresentableOfValue(const E& value) const {
            return value.toString();
        }

        virtual CString toString() const {
            return StringFormatter().dictionary<Key, E>(beginEnumeration());
        }

        // # Hashable

        ubig keysHashValue() const {
            MurmurHash64B hasher;

            ubig hash = 0;
            auto end = _map.end();

            for (auto it = _map.begin(); it != end; it++) {
                hash = hasher.combine(hash, hasher.hash(it->first));
            }

            return hash;
        }

        ubig valuesHashValue() const {
            MurmurHash64B hasher;

            ubig hash = 0;
            auto end = _map.end();

            for (auto it = _map.begin(); it != end; it++) {
                hash = hasher.combine(hash, hasher.hash(it->second));
            }

            return hash;
        }

        virtual ubig hashValue() const {
            MurmurHash64B hasher;
            return hasher.combine(keysHashValue(), valuesHashValue());
        }

        // # Copyable

        virtual Dictionary copy() const {
            return *this;
        }

        // # Enumeration

        virtual DictionaryIterator<Key, E> beginEnumeration() const {
            return DictionaryIterator<Key, E>(_map.cbegin(), _map.cend());
        }

        virtual MutableDictionaryIterator<Key, E> beginMutableEnumeration() {
            return MutableDictionaryIterator<Key, E>(_map.begin(), _map.end());
        }

        // # Convert

        template <typename Source>
        void mapTo(const Dictionary<Key, Source>& other) {
            using Destination = E;

            auto mapper = Mapper<Source, Destination>();
            auto iterator = other.beginEnumeration();
            auto parser = SimpleParser<Source, Destination>();
            auto result = mapper.mapPair<Dictionary<Key, Destination>, Key>(iterator, parser);
            addAll(result.beginEnumeration());
        }

        void transform(const Transformer<E>& transformer) {
            auto iterator = beginMutableEnumeration();

            while (iterator.hasNext()) {
                transformer.transform(iterator.get().second);
                iterator++;
            }
        }
    };
};
