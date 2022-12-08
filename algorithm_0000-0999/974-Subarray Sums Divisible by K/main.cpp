class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> m(k, 0); // index: reminder of presum => val: number of prefix
        //unordered_map<int, int> m; // reminder of presum => number of prefix
        m[0] = 1;

        int ret = 0;
        for (int presum = 0, i = 0; i < n; ++i) {
            presum += nums[i];
            int reminder = (presum % k + k) % k;

            ret += m[reminder];
            ++m[reminder];
        }
        return ret;
    }
};

/*
X X X X X X X X
      j       i
num[j+1, i] is divisible by k
presum[i] - presum[j] is divisible by k
=> presum[i] % k == presum[j] % k
*/
