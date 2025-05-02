class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ret = 0;
        for (int num : nums) {
            int cnt = 0;
            while (num) {
                num /= 10;
                ++cnt;
            }
            if ((cnt & 1) == 0) {
                ++ret;
            }
        }

        return ret;
    }
};
