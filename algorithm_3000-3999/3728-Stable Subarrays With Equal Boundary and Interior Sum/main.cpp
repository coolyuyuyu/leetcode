class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        long long ret = 0;

        unordered_map<int, unordered_map<long long, int>> m;
        long long sum = 0;
        for (int i = 0, n = capacity.size(); i < n; ++i) {
            sum += capacity[i];

            ret += m[capacity[i]][sum - capacity[i] * 2];

            if (i > 0) {
                m[capacity[i - 1]][sum - capacity[i]] += 1;
            }
        }

        return ret;
    }
};
