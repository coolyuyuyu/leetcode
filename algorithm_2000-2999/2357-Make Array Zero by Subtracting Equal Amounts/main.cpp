class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto itr = std::unique(nums.begin(), nums.end());
        nums.resize(std::distance(nums.begin(), itr));
        if (!nums.empty() && nums.front() == 0) {
            return nums.size() - 1;
        }
        else {
            return nums.size();
        }
    }
};