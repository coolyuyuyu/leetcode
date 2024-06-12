class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // X X X X X X X X
        //         j     i
        // sum(j+1, i) = presum(i) - presum(j) = n * k
        // => presum(i) % k == presum(j) % k

        vector<int> m(k, 0); // presum % k -> number of prefix
        m[0] = 1;

        int ret = 0;
        int presum = 0;
        for (int num : nums) {
            presum += num;

            int r = (presum % k + k) % k;
            ret += m[r];

            m[r] += 1;
        }

        return ret;
    }
};
