class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        std::function<int(int)> f = [](int num) {
            int sufCnt1 = 0;
            for (int tmp = num; tmp & 1; tmp >>= 1) {
                ++sufCnt1;
            }
            if (sufCnt1 == 0) {
                return -1;
            }

            return num & ~(1 << (sufCnt1 - 1));
        };

        int n = nums.size();
        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = f(nums[i]);
        }

        return ret;
    }
};
