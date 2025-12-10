class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        // X X X X [X X X] X X X X X
        // 0        i   j         n

        // given (sum(0:i-1) + sum(j+1, n)) % p == 0
        // let rem = sum(0:n) % p
        // => rem = (sum(0:i-1) + sum(i,j) + sum(j+1, n)) % p
        // => rem = sum(i,j) % p
        // => rem = (presum(j) - presum(i-1)) % p

        // let remJ = presum(j) % p
        // => presum(i-1) % p = remJ - rem

        int rem = 0;
        for (int num : nums) {
            rem = (rem + num) % p;
        }
        if (rem == 0) {
            return 0;
        }

        int ret = n;
        unordered_map<int, int> rem2idx = {{0, -1}};
        for (int j = 0, curRem = 0; j < n; ++j) {
            curRem = (curRem + nums[j]) % p;
            int preRem = ((curRem - rem) % p + p) % p;
            if (rem2idx.find(preRem) != rem2idx.end()) {
                int i = rem2idx[preRem] + 1;
                ret = std::min(ret, j - i + 1);
            }
            rem2idx[curRem] = j;
        }

        return ret < n ? ret : -1;
    }
};
