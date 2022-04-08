class Solution {
public:
    vector<string> findMissingRanges_BruteForce1(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) {
            string range = std::to_string(lower);
            if (lower < upper) {
                range += "->";
                range += std::to_string(upper);
            }
            return {range};
        }

        assert(lower <= nums.front() && nums.back() <= upper);

        vector<string> ranges;
        if (lower < nums.front()) {
            string range = std::to_string(lower);
            if ((lower + 1) < nums.front()) {
                range += "->";
                range += std::to_string(nums.front() - 1);
            }
            ranges.push_back(range);
        }
        for (size_t i = 1; i < nums.size(); ++i) {
            int dist = nums[i] - nums[i - 1];
            if (dist == 1) {
                continue;
            }

            string range = std::to_string(nums[i - 1] + 1);
            if (2 < dist) {
                range += "->";
                range += std::to_string(nums[i] - 1);
            }
            ranges.push_back(range);
        }
        if (nums.back() < upper) {
            string range = std::to_string(nums.back() + 1);
            if ((nums.back() + 1) < upper) {
                range += "->";
                range += std::to_string(upper);
            }
            ranges.push_back(range);
        }

        return ranges;
    }

    vector<string> findMissingRanges_BruteForce2(vector<int>& nums, int lower, int upper) {
        vector<string> ranges;
        int preNum = lower - 1;
        for (size_t i = 0; i <= nums.size(); ++i) {
            int curNum = i < nums.size() ? nums[i] : upper + 1;
            int dist = curNum - preNum;
            if (1 < dist) {
                string range = std::to_string(preNum + 1);
                if (2 < dist) {
                    range += "->";
                    range += std::to_string(curNum - 1);
                }
                ranges.push_back(range);
            }

            preNum = curNum;
        }

        return ranges;
    }

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        //return findMissingRanges_BruteForce1(nums, lower, upper);
        return findMissingRanges_BruteForce2(nums, lower, upper);
    }
};