class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> ret(m, true);
        for (int i = 0; i < m; ++i) {
            vector<int> tmp(nums.begin() + l[i], nums.begin() + r[i] + 1);
            std::sort(tmp.begin(), tmp.end());
            for (int j = 2; j < tmp.size(); ++j) {
                if (tmp[j] - tmp[j - 1] != tmp[1] - tmp[0]) {
                    ret[i] = false;
                    break;
                }
            }
        }

        return ret;
    }
};
