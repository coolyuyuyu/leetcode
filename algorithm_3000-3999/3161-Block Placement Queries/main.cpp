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

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> obstacles({0});
        int maxval = -1;
        for (const auto& query : queries) {
            int t = query[0], x = query[1];
            if (query[0] == 1) {
                obstacles.insert(x);
            }
            maxval = std::max(maxval, x);
        }

        MaxFenwick<int> fw(maxval + 1);
        for (auto itr = std::next(obstacles.begin()); itr != obstacles.end(); ++itr) {
            fw.set(*itr, *itr - *std::prev(itr));
        }

        vector<bool> ret;
        for (int i = queries.size() - 1; i >= 0; --i) {
            int t = queries[i][0], x = queries[i][1];
            auto itr = obstacles.lower_bound(x);
            if (t == 1) {
                if (std::next(itr) != obstacles.end()) {
                    fw.set(*std::next(itr), *std::next(itr) - *std::prev(itr));
                }
                obstacles.erase(itr);
            }
            else {
                int sz = queries[i][2];
                ret.push_back(x - *std::prev(itr) >= sz || fw.max(x) >= sz);
            }
        }
        std::reverse(ret.begin(), ret.end());

        return ret;
    }
};
