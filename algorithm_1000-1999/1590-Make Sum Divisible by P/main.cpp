class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // X X X X X X X X X X X X
        //         i   j         n

        // given (sum(0:i-1) + sum(j+1, n)) % p == 0
        // let remAll = sum(0:n) % p
        // => remAll = (sum(0:i-1) + sum(i,j) + sum(j+1, n)) % p
        // => remAll = sum(i,j) % p
        // => remAll = (presum(j) - presum(i-1)) % p

        // let remJ = presum(j) % p
        // => presum(i-1) % p = remJ - remAll

        int n = nums.size();

        int rem = 0;
        for (int num : nums) {
            rem = (rem + num) % p;
        }
        if (rem == 0) { return 0; }

        unordered_map<int, int> rem2idx = {{0, -1}};

        int ret = n;
        for (int j = 0, preRem = 0; j < nums.size(); ++j) {
            preRem = (preRem + nums[j]) % p;

            int x = ((preRem - rem) % p + p) % p;
            if (rem2idx.find(x) != rem2idx.end()) {
                int i = rem2idx[x] + 1;
                ret = std::min(ret, j - i + 1);
            }

            rem2idx[preRem] = j;
        }
        if (ret == n) {
            ret = -1;
        }

        return ret;
    }
};
