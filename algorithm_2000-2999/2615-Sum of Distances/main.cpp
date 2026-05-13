class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> num2idxs;
        for (int i = 0; i < n; ++i) {
            num2idxs[nums[i]].push_back(i);
        }

        vector<long long> ret(n);
        for (const auto& [_, idxs] : num2idxs) {
            for (int i = 1; i < idxs.size(); ++i) {
                ret[idxs[0]] += idxs[i] - idxs[0];
            }

            for (int i = 1; i < idxs.size(); ++i) {
                long long d = idxs[i] - idxs[i - 1];
                ret[idxs[i]] = ret[idxs[i - 1]] + d * i - d * (idxs.size() - i);
            }
        }

        return ret;
    }
};
