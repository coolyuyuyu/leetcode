class Solution {
public:
    // slide window, Time: O(n)
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();

        map<int, long long> m;
        long long sum = 0, cnt = 0;
        for (int lft = 0, rht = 0; lft < n; ++lft) {
            while (sum < k) {
                if (rht == n) {
                    break;
                }

                sum += m[nums[rht]]++;
                ++rht;
            }
            if (sum >= k) {
                cnt += (n - rht + 1);
            }

            sum -= --m[nums[lft]];
        }

        return cnt;
    }
};
