class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();


        int uniqueCnt = 0;
        unordered_map<int, int> cnts;
        long sum = 0;

        long ret = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (++cnts[nums[i]] == 1) {
                ++uniqueCnt;
            }

            if (i + 1 >= k) {
                if (uniqueCnt == k) {
                    ret = std::max(ret, sum);
                }

                sum -= nums[i + 1 - k];
                if (--cnts[nums[i + 1 - k]] == 0) {
                    --uniqueCnt;
                }
            }
        }

        return ret;

    }
};
