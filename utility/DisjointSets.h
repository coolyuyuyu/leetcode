#include <map>

template<typename T>
class DisjointSets {
public:
    DisjointSets() {
    }
    DisjointSets(std::initializer_list<pair<T, T> list)
    void clear();
    bool make_set(const T& elem);
    bool merge(const T& elem1, const T& elem2) // link? // return false if already merged
    bool contain(const T& elem) const;
    
    size_t size() const;
    
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