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

//Container = std::map<T, pair<T, size_t>> <val, <parent, cardinality>>
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

    // false: alreay belong to 1 set
    bool make_set(const T& val);

    bool merge(const T& val1, const T& val2) // link? // return false if already merged
    bool connected(const T& val1, const T& val2)
    

    bool contain(const T& val) const {
        bool found;
        findRoot(val, found);
        
        return found;
    }

    size_t size() const {
        return m_size;
    }
    
    // num of elment in one set
    size_t cardinality(const T& val) const {
        bool found;
        findRoot(val, found);
    }
    
    bool sigleton const (const T& val) {
        
    }

    std::set<T> set(const T& elem) const;
    std::vector<std::set<T>> sets(const T& elem) const;

private:
    const T& findRoot(const T& elem, bool& found) const {
        
    } // return found

    mutable Container m_map;
    Equal m_equal;
    size_t m_size;
};

#endif
