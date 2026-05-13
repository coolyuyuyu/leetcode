class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> num2idxs;
        for (int i = 0; i < n; ++i) {
            num2idxs[nums[i]].push_back(i);
        }

        std::function<int(int, int)> computeDist = [&](int a, int b) {
            if (a > b) { std::swap(a, b); }
            return std::min(b - a, n - b + a);
        };

        vector<int> ret(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i) {
            int cur = queries[i];
            vector<int>& idxs = num2idxs[nums[cur]];
            if (idxs.size() == 1) {
                continue;
            }

            auto itr = std::lower_bound(idxs.begin(), idxs.end(), cur);
            int pre = cur != idxs.front() ? *std::prev(itr) : idxs.back();
            int nxt = cur != idxs.back() ? *std::next(itr) : idxs.front();
            ret[i] = std::min(computeDist(pre, cur), computeDist(cur, nxt));
        }

        return ret;
    }
};
