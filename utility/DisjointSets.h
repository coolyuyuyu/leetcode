#include <map>

template<typename T>
class DisjointSets {
public:
    DisjointSets()
        : m_size(0) {
    }

    DisjointSets(std::initializer_list<pair<T, T> list)
        : m_size(0) {
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

    bool contain(const T& elem) const;

    size_t size() const {
        return m_size;
    }

    set<T> set(const T& elem) const;
    vector<set<T>> sets(const T& elem) const;

private:
    bool root(const T& elem, T& root) const // return found

    size_t m_size;
    std::map<T, T> m_map;
};

/*
Optimization:
    path compression
    merge by rank
*/