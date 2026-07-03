template<typename T, typename Alloc = std::allocator<T>>
class MaxFenwick {
public:
    MaxFenwick(std::size_t size)
        : m_bits(size + 1, defval()) {
    }

    template<typename InputIterator>
    explicit MaxFenwick(InputIterator first, InputIterator last)
        : m_bits(std::distance(first, last), defval()) {
        for (std::size_t i = 0; first != last; ++i, ++first) {
            set(i, *first);
        }
    }

    std::size_t size() const {
        return m_bits.size() - 1;
    }

    // the value can only increase
    void set(std::size_t i, T v) {
        assert(i < m_bits.size());

        for (std::size_t idx = i + 1; idx <= size(); idx += lowbit(idx)) {
            m_bits[idx] = std::max(m_bits[idx], v);
        }
    }

    T max(std::size_t i) const {
        assert(i < m_bits.size());

        T ret = defval();
        for (std::size_t idx = i + 1; idx > 0; idx -= lowbit(idx)) {
            ret = std::max(ret, m_bits[idx]);
        }

        return ret;
    }

private:
    static T defval() {
        return std::numeric_limits<T>::min();
    }

    static std::size_t lowbit(std::size_t idx) {
        assert(idx > 0);
        return idx & ~(idx - 1);
    }

    std::vector<T, Alloc> m_bits;
};
