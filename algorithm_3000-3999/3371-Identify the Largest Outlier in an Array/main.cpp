class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> cnts;
        int sum = 0;
        for (int num : nums) {
            ++cnts[num];
            sum += num;
        }

        for (int i = nums.size(); 0 < i--;) {
            --cnts[nums[i]];
            sum -= nums[i];

            if (sum % 2 == 0 && cnts[sum / 2] >= 1) {
                return nums[i];
            }

            sum += nums[i];
            ++cnts[nums[i]];
        }

        __builtin_unreachable();
        return -1;
    }
};
