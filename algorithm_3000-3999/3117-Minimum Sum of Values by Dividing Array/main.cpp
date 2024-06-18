class Solution {
public:
    int MASK = (2 << 17) - 1;
    int INF = INT_MAX / 10;

    unordered_map<int, int> cache[10000][10];

    int helper(vector<int>& nums, vector<int>& andValues, int i, int j, int val) {
        int m = nums.size(), n = andValues.size();
        if (i == m && j == n) { return 0; }
        else if (i == m || j == n) { return INF; }
        else if (m - i < n - j) { return INF; }

        if (cache[i][j].find(val) != cache[i][j].end()) {
           return cache[i][j][val];
        }

        int& ret = cache[i][j][val];
        val &= nums[i];
        if (val < andValues[j]) {
            ret = INF;
        }
        else if (val > andValues[j]) {
            ret = helper(nums, andValues, i + 1, j, val);
        }
        else {
            ret = std::min(nums[i] + helper(nums, andValues, i + 1, j + 1, MASK), helper(nums, andValues, i + 1, j, val));
        }

        return ret;
    }

    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int ret = helper(nums, andValues, 0, 0, MASK);
        return ret < INF ? ret : -1;
    }
};
