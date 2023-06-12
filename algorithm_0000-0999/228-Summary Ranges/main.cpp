class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        for (size_t lft = 0, rht = 1; rht <= nums.size(); ++rht) {
            if (rht == nums.size() || (nums[rht - 1] + 1) < nums[rht]) {
                string range = std::to_string(nums[lft]);
                if ((lft + 1) < rht) {
                    range += ("->" + std::to_string(nums[rht - 1]));
                }
                ret.push_back(range);

                lft = rht;
            }
        }

        return ret;
    }
};
