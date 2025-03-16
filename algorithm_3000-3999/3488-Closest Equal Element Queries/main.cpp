class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();

        unordered_map<int, vector<int>> num2indexes;
        for (int i = 0; i < nums.size(); ++i) {
            num2indexes[nums[i]].push_back(i);
        }

        std::function<int(int, int)> computeDist = [&](int a, int b) {
            if (a > b) { std::swap(a, b); }
            return std::min(b - a, n - b + a);
        };

        vector<int> ret(m);
        for (int i = 0; i < m; ++i) {
            const vector<int>& indexes = num2indexes[nums[queries[i]]];
            if (indexes.size() == 1) {
                ret[i] = -1;
            }
            else {
                auto itr = std::lower_bound(indexes.begin(), indexes.end(), queries[i]);
                int cur = queries[i];
                int nxt = (cur == indexes.back() ? indexes.front() : *std::next(itr));
                int pre = (cur == indexes.front() ? indexes.back() : *std::prev(itr));
                ret[i] = std::min(computeDist(pre, cur), computeDist(cur, nxt));
            }
        }
        return ret;
    }
};
