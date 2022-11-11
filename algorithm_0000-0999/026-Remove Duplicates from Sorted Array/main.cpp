class Solution {
public:
    int bruteforce(vector<int>& nums) {
        size_t i = 0;
        for (size_t j = 1; j < nums.size(); ++j) {
            if (nums[i] < nums[j]) {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }

    int binarySearch(vector<int>& nums) {
        size_t i = 0;
        for (auto itr = nums.begin(); (itr = std::lower_bound (itr + 1, nums.end(), *itr + 1)) != nums.end();) {
            nums[++i] = *itr;
        }
        return i + 1;
    }

    int removeDuplicates(vector<int>& nums) {
        assert(!nums.empty());

        //return bruteforce(nums);
        return binarySearch(nums);
    }
};
