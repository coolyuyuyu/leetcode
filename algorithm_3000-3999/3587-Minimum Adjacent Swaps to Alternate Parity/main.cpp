class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> indexesO;
        for (int i = 0; i < n; ++i) {
            if (nums[i] & 1) { indexesO.push_back(i); }
        }
        int cntO = indexesO.size(), cntE = n - cntO;
        if (std::abs(cntE - cntO) >= 2) {
            return -1;
        }

        if (cntE == cntO) {
            int ret1 = 0;
            for (int i = 0, j = 0; i < n; i += 2, ++j) {
                ret1 += std::abs(i - indexesO[j]);
            }

            int ret2 = 0;
            for (int i = 1, j = 0; i < n; i += 2, ++j) {
                ret2 += std::abs(i - indexesO[j]);
            }

            return std::min(ret1, ret2);
        }
        else {
            int ret = 0;
            for (int i = (cntO > cntE ? 0 : 1), j = 0; i < n; i += 2, ++j) {
                ret += std::abs(i - indexesO[j]);
            }

            return ret;
        }
    }
};