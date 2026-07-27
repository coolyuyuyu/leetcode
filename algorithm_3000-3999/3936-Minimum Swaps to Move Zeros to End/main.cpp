class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int cnt0 = std::count(nums.begin(), nums.end(), 0);

        return std::count_if(nums.end() - cnt0, nums.end(), [](int num){ return num != 0; });
    }
};
