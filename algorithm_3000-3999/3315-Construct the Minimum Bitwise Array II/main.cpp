class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        std::function<int(int)>f = [](int num) {
            int tmp = num;
            int cntSecutive1 = 0;
            while (tmp & 1) {
                cntSecutive1 += 1;
                tmp >>= 1;
            }
            if (cntSecutive1 == 0) {
                return -1;
            }

            return num & ~(1 << (cntSecutive1 - 1));
        };

        int n = nums.size();
        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = f(nums[i]);
        }

        return ret;
    }
};
