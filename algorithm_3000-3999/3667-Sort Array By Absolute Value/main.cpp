class Solution {
public:
    vector<int> sortByAbsoluteValue(vector<int>& nums) {
        auto comp = [](int a, int b) {
            return std::abs(a) < std::abs(b);
        };
        std::sort(nums.begin(), nums.end(), comp);

        return nums;
    }
};
