class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        for (size_t i = 1, j = 0; (i + 1) < nums.size(); ++i) {
            if ((nums[j] > nums[i] && nums[i] < nums[i + 1]) || // valley
                (nums[j] < nums[i] && nums[i] > nums[i + 1])) { // hill
                ++cnt;
                j = i;
            }
        }

        return cnt;
    }
};
