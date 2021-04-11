#ifndef __DISJOINT_SETS_H__493A883A_6A4F_4328_8CB1_58CB15279742
#define __DISJOINT_SETS_H__493A883A_6A4F_4328_8CB1_58CB15279742

#include <initializer_list>
#include <functional>
#include <map>

/*
Optimization:
    path compression
    merge by rank
*/

template<typename T, class Container = std::map<T, T>, class Equal = std::equal_to<typename Container::key_type>>
class DisjointSets {
public:
    static_assert(std::is_same<T, typename Container::key_type>::value, "key_type must be the same as the underlying container key_type");
    static_assert(std::is_same<T, typename Container::mapped_type>::value, "mapped_type must be the same as the underlying container mapped_type");

    DisjointSets(const Equal& equal = Equal())
        : m_equal(equal)
        , m_size(0) {
    }

    DisjointSets(std::initializer_list<pair<T, T> list, const Equal& equal = Equal())
        : m_equal(equal)
        , m_size(0) {
        for (const std::pair<T, T>& p : list) {
            merge(p.first, p.second);
        }
    }

    void clear() {
        m_size = 0;
        m_map.clear();
    }

    void swap(DisjointSets<T>& rhs) {
        swap(m_size, rhs.m_size);
        m_map.swap(rhs.m_map);
    }

    bool make_set(const T& elem);

    bool merge(const T& elem1, const T& elem2) // link? // return false if already merged

    bool contain(const T& elem) const {
        T root;
        return (root(elem, root));
    }

    size_t size() const {
        return m_size;
    }

    std::set<T> set(const T& elem) const;
    std::vector<std::set<T>> sets(const T& elem) const;

private:
    bool root(const T& elem, T& root) const // return found

    Equal m_equal;
    size_t m_size;
    mutable Container m_map;
};

#endif
