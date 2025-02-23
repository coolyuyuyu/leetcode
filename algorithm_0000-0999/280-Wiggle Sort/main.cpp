class Solution {
public:
    // Time: O(NlogN)
    void bySort(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 2, n = nums.size(); i < n; i += 2) {
            std::swap(nums[i - 1], nums[i]);
        }
    }

    // Time: O(N)
    void byGreedy(vector<int>& nums) {
        for (int i = 0, n = nums.size(); i + 1 < n; ++i) {
            if (i & 1) {
                if (nums[i] < nums[i + 1]) {
                    std::swap(nums[i], nums[i + 1]);
                }
            }
            else {
                if (nums[i] > nums[i + 1]) {
                    std::swap(nums[i], nums[i + 1]);
                }
            }
        }
    }

    void wiggleSort(vector<int>& nums) {
        //bySort(nums);
        byGreedy(nums);
    }
};
