class Solution {
public:
    int removeDuplicates_BruteForce(vector<int>& nums) {
        size_t i = 0;
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] < nums[j]) {
                nums[++i] = nums[j];
            }
        }

        return i + 1;
    }

    int removeDuplicates_BinarySearch(vector<int>& nums) {
        size_t i = 0;
        auto first = nums.begin() + i + 1;
        auto last = nums.end();
        while (true) {
            auto itr = std::lower_bound(first, last, nums[i] + 1);
            if (itr != last) {
                nums[++i] = *itr;
                first += 1;
            }
            else {
                break;
            }
        }

        return i + 1;
    }

    int removeDuplicates(vector<int>& nums) {
        assert(!nums.empty());

        //return removeDuplicates_BruteForce(nums);
        return removeDuplicates_BinarySearch(nums);
    }
};
