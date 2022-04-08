class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        for (size_t preIdx = 0, idx = 1; idx <= nums.size(); ++idx) {
            if (idx == nums.size() || (nums[idx - 1] + 1 < nums[idx])) {
                string range = std::to_string(nums[preIdx]);
                if ((preIdx + 1) < idx) {
                    range += "->";
                    range += std::to_string(nums[idx - 1]);
                }
                ranges.push_back(range);

                preIdx = idx;
            }
        }

        return ranges;
    }
};
