class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;
        for (int num : nums) {
            if ((num & 1) == 0) {
                if (++cnt == 2) {
                    return true;
                }
            }
        }

        return false;
    }
};
