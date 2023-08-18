class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int m = nums.size(), n = nums.empty() ? 0 : nums[0].size();

        vector<pair<string, int>> pairs(m);
        for (int i = 0; i < m; ++i) {
            pairs[i] = {nums[i], i};
        }

        class Comp {
        public:
            Comp(int pos, int len)
                : m_pos(pos)
                , m_len(len) {}
            bool operator() (const pair<string, int>& lhs, const pair<string, int>& rhs) const {
                int ret = lhs.first.compare(m_pos, m_len, rhs.first, m_pos, m_len);
                return ret < 0 || (ret == 0 && lhs.second < rhs.second);
            }
        private:
            int m_pos;
            int m_len;
        };
        std::function<pair<string, int>(int, int, int, const Comp&)> quickselect = [&](int lo, int hi, int k, const Comp& comp) {
            // M: pivot
            // S: less than pivot
            // L: greater than pivot
            // X: unknown
            // S S S S S M M M M M X X X X X L L L L L
            //           i         x       j
            pair<string, int> pivot = pairs[lo + (hi - lo) / 2];
            int i = lo, j = hi, x = lo;
            while (x <= j) {
                if (comp(pairs[x], pivot)) {
                    std::swap(pairs[i], pairs[x]);
                    ++i, ++x;
                }
                else if (!comp(pivot, pairs[x])) {
                    ++x;
                }
                else {
                    std::swap(pairs[x], pairs[j]);
                    --j;
                }
            }

            // S S S S S M M M M M L L L L L
            // lo        i       j         hi
            if (k < (i - lo)) {
                return quickselect(lo, i - 1, k, comp);
            }
            else if (k < (j + 1 - lo)) {
                return pivot;
            }
            else {
                return quickselect(j + 1, hi, k - (j + 1 - lo), comp);
            }
        };

        vector<int> ret(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int k = queries[i][0] - 1;
            int len = queries[i][1];
            //std::nth_element(pairs.begin(), pairs.begin() + k, pairs.end(), Comp(n - len, len));
            quickselect(0, m  - 1, k, Comp(n - len, len));

            ret[i] = pairs[k].second;
        }

        return ret;
    }
};
