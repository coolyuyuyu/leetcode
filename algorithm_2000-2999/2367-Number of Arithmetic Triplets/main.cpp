class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        vector<bool> existed(201, false);

        int cnt = 0;
        for (int num : nums) {
            if (2 * diff <= num && existed[num - diff] && existed[num - diff - diff]) {
                ++cnt;
            }
            existed[num] = true;
        }

        return cnt;
    }
};
