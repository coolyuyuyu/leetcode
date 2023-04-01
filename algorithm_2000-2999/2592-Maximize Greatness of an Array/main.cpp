class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
           if (nums[ret] < nums[i]) {
               ++ret;
           }
        }

        return ret;
    }
};
