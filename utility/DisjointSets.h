template<typename T>
class DisjointSets {
public:
    DisjointSets() {
    }
    DisjointSets(std::initializer_list<T> list)
    void clear();
    void make_set(const T& elem);
    void merge(const T& elem1, const T& elem2) // link?
    const T root(const T& elem) const
    size_t size() const;
    
private:
    std::map<T, T> m_map;
};