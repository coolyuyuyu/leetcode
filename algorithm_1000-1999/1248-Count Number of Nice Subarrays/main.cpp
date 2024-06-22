class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // 992. Subarrays with K Different Integers
        int n = nums.size();
        std::function<int(int)> atMost = [&](int k) {
            int ret = 0;
            for (int lft = 0, rht = 0, cnt = 0; lft < n; ++lft) {
                while (rht < n && (cnt < k || (cnt == k && (nums[rht] % 2 == 0)))) {
                    cnt += nums[rht] & 1;
                    ++rht;
                }

                ret += rht - lft;

                cnt -= nums[lft] & 1;
            }

            return ret;
        };

        return atMost(k) - atMost(k - 1);
    }
};
