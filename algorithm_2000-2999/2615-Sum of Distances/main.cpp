class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int m = nums.size();

        unordered_map<int, vector<int>> num2indexes;
        for (int i = 0; i < m; ++i) {
            num2indexes[nums[i]].push_back(i);
        }

        vector<long long> ret(m);
        for (const auto& [_, indexes] : num2indexes) {
            int n = indexes.size();

            long long sum = 0;
            for (int i = 1; i < n; ++i) {
                sum += (indexes[i] - indexes[0]);
            }
            ret[indexes[0]] = sum;

            for (int i = 1; i < n; ++i) {
                int diff = indexes[i] - indexes[i - 1];
                sum += (i) * diff;
                sum -= (n - i) * diff;
                ret[indexes[i]] = sum;
            }
        }

        return ret;
    }
};
