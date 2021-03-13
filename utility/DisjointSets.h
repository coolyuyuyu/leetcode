template<typename T>
class DisjointSets {
public:
    DisjointSets() {
    }
    DisjointSets(std::initializer_list<T> list)
    void clear();
    void make_set(const T& elem);
    void merge(const T& elem1, const T& elem2) // link? // return false if already merged
    bool contain() const;
    
    size_t size() const;
    
    set<T> set(const T& elem) const;
    vector<set<T>> sets(const T& elem) const;
    
private:
    const T& root(const T& elem) const

    std::map<T, T> m_map;
    size_t m_size;
};

/*
Optimization:
    path compression
    merge by rank
*/