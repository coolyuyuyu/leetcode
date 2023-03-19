class Solution {
public:
    int maxScore(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());

        int i = 0;
        for (long long sum = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum <= 0) {
                break;
            }
        }

        return i;
    }
};
