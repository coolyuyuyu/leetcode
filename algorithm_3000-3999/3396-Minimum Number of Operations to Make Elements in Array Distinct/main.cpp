class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> cnts;
        int dupCnt = 0;
        for (int num : nums) {
            if (++cnts[num] == 2) {
                ++dupCnt;
            }
        }

        int ret = 0;
        for (int i = 0, n = nums.size(); i < n && dupCnt > 0; i += 3, ++ret) {
            if (--cnts[nums[i]] == 1) {
                --dupCnt;
            }
            if (i + 1 < n && --cnts[nums[i + 1]] == 1) {
                --dupCnt;
            }
            if (i + 2 < n && --cnts[nums[i + 2]] == 1) {
                --dupCnt;
            }
        }

        return ret;
    }
};
