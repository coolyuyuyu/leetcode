
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

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SparseTable<int, std::ranges::max> stMax(nums.begin(), nums.end());
        SparseTable<int, std::ranges::min> stMin(nums.begin(), nums.end());

        priority_queue<tuple<int, int, int>> pq; // <val, l, r>
        for (int i = 0; i < n; ++i) {
            pq.emplace(stMax.query(i, n - 1) - stMin.query(i, n - 1), i, n - 1);
        }

        long long ret = 0;
        while (k-- > 0 && !pq.empty()) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ret += val;

            if (l < r) {
                pq.emplace(stMax.query(l, r - 1) - stMin.query(l, r - 1), l, r - 1);
            }
        }

        return ret;
    }
};
