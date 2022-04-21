class Solution {
public:
    // Time: O(NlogN)
    vector<int> sortByLastBit(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int a, int b) { return a % 2 < b % 2; });

        return nums;
    }

    // Time: O(N)
    vector<int> linearSwap(vector<int>& nums) {
        assert(!nums.empty());

        for (size_t i = 0, j = nums.size() - 1; i < j; ++i) {
            if (nums[i] % 2 == 1) {
                for (; i < j; --j) {
                    if (nums[j] % 2 == 0) {
                        std::swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }

        return nums;
    }

    vector<int> sortArrayByParity(vector<int>& nums) {
        //return sortByLastBit(nums);
        return linearSwap(nums);
    }
};
