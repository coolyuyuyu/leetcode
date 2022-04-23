class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        assert(3 <= nums.size());
        for (size_t i = nums.size(); 2 < i--;) {
            if (nums[i] < (nums[i - 2] + nums[i - 1])) {
                cout << i << endl;
                return (nums[i - 2] + nums[i - 1] + nums[i]);
            }
        }

        return 0;
    }
};
