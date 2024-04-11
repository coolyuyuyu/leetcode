class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        vector<int> indexes;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                indexes.push_back(i);
            }
        }
        int n = indexes.size();

        maxChanges = std::min(maxChanges, k);

        long long ret = LLONG_MAX;
        if (maxChanges - 0 >= 0 && k - maxChanges + 0 <= n) {
            ret = std::min(ret, (maxChanges - 0) * 2 + helper(indexes, k - maxChanges + 0));
        }
        if (maxChanges - 1 >= 0 && k - maxChanges + 1 <= n) {
            ret = std::min(ret, (maxChanges - 1) * 2 + helper(indexes, k - maxChanges + 1));
        }
        if (maxChanges - 2 >= 0 && k - maxChanges + 2 <= n) {
            ret = std::min(ret, (maxChanges - 2) * 2 + helper(indexes, k - maxChanges + 2));
        }
        if (maxChanges - 3 >= 0 && k - maxChanges + 3 <= n) {
            ret = std::min(ret, (maxChanges - 3) * 2 + helper(indexes, k - maxChanges + 3));
        }

        return ret;
    }

    long long helper(vector<int>& indexes, int k) {
        if (k == 0) {
            return 0;
        }

        int n = indexes.size();
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += std::abs(indexes[i] - indexes[k / 2]);
        }

        long long ret = sum;
        for (int i = 0; i + k < n; ++i) {
            int d = indexes[i + k / 2 + 1]  - indexes[i + k / 2];
            sum = sum + d * (k / 2 + 1) - d * (k - (k / 2 + 1)) - (indexes[i + k / 2 + 1] - indexes[i + 0]) + (indexes[i + k] - indexes[i + k / 2 + 1]);
            ret = std::min(ret, sum);
        }

        return ret;
    }
};
