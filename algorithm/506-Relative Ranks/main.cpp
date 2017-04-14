class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> ranks(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            ranks[i] = i;
        }
        sort(ranks.begin(), ranks.end(), [&](int a, int b) { return nums[a] > nums[b]; });

        vector<string> result(nums.size());
        
        if (0 < result.size())
            result[ranks[0]] = "Gold Medal";
        if (1 < result.size())
            result[ranks[1]] = "Silver Medal";
        if (2 < result.size())
            result[ranks[2]] = "Bronze Medal";
        for (size_t i = 3; i < nums.size(); ++i) {
            result[ranks[i]] = to_string(i + 1);
        }

        return result;
    }
};