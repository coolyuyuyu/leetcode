class Solution {
public:
    // Time: O(NlogN)
    void bySort(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (size_t i = 2; i < nums.size(); i += 2) {
            std::swap(nums[i - 1], nums[i]);
        }
    }

    // Time: O(N)
    void byGreedy(vector<int>& nums) {
        for (size_t i = 1; i < nums.size(); ++i) {
            if (i % 2) { // odd index
                if (nums[i] < nums[i - 1]) {
                    std::swap(nums[i - 1], nums[i]);
                }
            }
            else { // even index
                if (nums[i - 1] < nums[i]) {
                    std::swap(nums[i - 1], nums[i]);
                }
            }
        }
    }
    void wiggleSort(vector<int>& nums) {
        //bySort(nums);
        byGreedy(nums);
    }
};
