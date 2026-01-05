class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;

        int ret = INT_MAX;
        for (int i = 0, j = 0, sum = 0, n = nums.size(); i < n; ++i) {
            for (; j < n && sum < k; ++j) {
                if (++cnts[nums[j]] == 1) {
                    sum += nums[j];
                }
            }

            if (sum >= k) {
                ret = std::min(ret, j - i);
            }

            if (--cnts[nums[i]] == 0) {
                sum -= nums[i];
            }
        }

        return ret < INT_MAX ? ret : -1;
    }
};
