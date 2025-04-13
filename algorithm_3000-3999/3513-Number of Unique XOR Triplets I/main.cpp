class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return n;
        }

        int ret = 1;
        for (; n; n >>= 1) {
            ret *= 2;
        }

        return ret;
    }
};
