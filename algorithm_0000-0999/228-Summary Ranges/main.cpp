class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for (size_t index = 1, preIndex = 0; index <= nums.size(); ++index) {
            if (nums.size() == index || index - preIndex < nums[index] - nums[preIndex]) {
                string range = to_string(nums[preIndex]);
                if(preIndex + 1 < index) {
                    range += "->";
                    range += to_string(nums[index - 1]);
                }
                ans.emplace_back(range);

                preIndex = index;
            }
        }
        return ans;
    }
};