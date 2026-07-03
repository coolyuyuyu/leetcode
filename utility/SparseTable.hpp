
template<typename T, auto BinaryOperation = std::ranges::min>
class SparseTable {
public:
    template<typename InputIterator>
    explicit SparseTable(InputIterator first, InputIterator last){
        assert(first != last);

        std::size_t n = std::distance(first, last);
        unsigned K = std::bit_width<unsigned>(n);

        m_vals = new T* [K];
        for (unsigned k = 0; k < K; ++k) {
            m_vals[k] = new T[n];
        }

        for (int i = 0; i < n; ++i, ++first) {
            m_vals[0][i] = *first;
        }
        for (unsigned k = 1; k < K; ++k) {
            std::size_t len = 1ull << k;
            std::size_t half = len >> 1;
            for (int i = 0; i + len <= n; ++i) {
                m_vals[k][i] = BinaryOperation(m_vals[k - 1][i], m_vals[k - 1][i + half]);
            }
        }
    }

    T query(std::size_t lo, std::size_t hi) {
        assert(lo <= hi);

        std::size_t len = hi - lo + 1;
        unsigned k = std::bit_width<unsigned>(len) - 1;
        return BinaryOperation(m_vals[k][lo], m_vals[k][hi - (1ull << k) + 1]);
    }

private:
    T** m_vals;
};
