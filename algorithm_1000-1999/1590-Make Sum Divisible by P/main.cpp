class Solution {
public:
    // hash + prefix sum
    int minSubarray(vector<int>& nums, int p) {
        assert(!nums.empty());

        int r; {
            int sum = 0;
            for (int num : nums) {
                sum = (sum + num) % p;
            }
            r = sum % p;
        }
        if (r == 0) {
            return 0;
        }

        unordered_map<int, int> m; // key: presum % p, val: biggest index
        m[0] = -1;

        int ret = nums.size();
        for (int presum = 0, i = 0; i < nums.size(); ++i) {
            presum = (presum + nums[i]) % p;
            int diff = (presum + p - r) % p;
            if (m.find(diff) != m.end()) {
                ret = std::min(ret, i - m[diff]);
            }

            m[presum] = std::max(m[presum] , i);
        }

        return (ret == nums.size()) ? -1 : ret;
    }
};

/*
X X X X X X X X X X
      i     j     n
assume r: sum[0,n] % p
(sum[0,i] + sum[j+1,n]) is divisible by p
=> sum[i+1,j] % p == r
=> (presum[i] - presum[j]) % p == r
*/
