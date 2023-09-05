class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long sum = 0;
        unordered_map<int, int> cnts;
        int uniqueCnt = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
            if (++cnts[nums[i]] == 1) {
                ++uniqueCnt;
            }
        }

        long long ret = (m <= uniqueCnt ? sum : 0);
        for (int i = k; i < nums.size(); ++i) {
            sum -= nums[i - k];
            sum += nums[i];

            if (--cnts[nums[i - k]] == 0) {
                --uniqueCnt;
            }
            if (++cnts[nums[i]] == 1) {
                ++uniqueCnt;
            }

            if (m <= uniqueCnt) {
                ret = std::max(ret, sum);
            }
        }

        return ret;
    }
};
