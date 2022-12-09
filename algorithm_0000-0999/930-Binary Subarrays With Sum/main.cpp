class Solution {
public:
    // hash + prefix sum
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> m; // key: presum, val: number of prefix
        m[0] = 1;
        int ret = 0;
        for (int presum = 0, i = 0; i < nums.size(); ++i) {
            presum += nums[i];
            if (goal <= presum) {
                ret += m[presum - goal];
            }
            ++m[presum];
        }
        return ret;
    }
};

/*
X X X X X X X
    j       i

sum[j+1:i] = presum[i] - presum[j] = k
*/
