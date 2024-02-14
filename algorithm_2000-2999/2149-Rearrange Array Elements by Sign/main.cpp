class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        int eNums[n / 2], eIdx = 0;
        int oNums[n / 2], oIdx = 0;
        for (int num : nums) {
            if (num > 0) {
                oNums[oIdx++] = num;
            }
            else {
                eNums[eIdx++] = num;
            }
        }

        for (int i = 0; i * 2 < n; ++i) {
            nums[i * 2] = oNums[i];
            nums[i * 2 + 1] = eNums[i];
        }

        return nums;
    }
};
