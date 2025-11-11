class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        int pre1[n + 1], pre2[n + 1];
        std::fill(pre1, pre1 + n + 1, -1);
        std::fill(pre2, pre2 + n + 1, -1);

        int ret = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (pre2[num] != -1) {
                int j = pre1[num], k = pre2[num];
                ret = std::min(ret, (i - j) + (j - k) + (i - k));
            }
            
            pre2[num] = pre1[num];
            pre1[num] = i;
        }

        return ret != INT_MAX ? ret : -1;
    }
};
