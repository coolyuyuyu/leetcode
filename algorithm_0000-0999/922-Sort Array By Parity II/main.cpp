class Solution {
public:
    // Time: O(N)
    vector<int> linearSwap(vector<int>& nums) {
        for (size_t i = 0, j = 1; i < nums.size() && j < nums.size(); i += 2) {
            if (nums[i] % 2 == 1) {
                for (; j < nums.size(); j += 2) {
                    if (nums[j] % 2 == 0) {
                        swap(nums[i], nums[j]);
                        j += 2;
                        break;
                    }
                }
            }
        }

        return nums;
    }

    // Time: O(NlogN)
    vector<int> sortAndSwap(vector<int>& nums) {
        // move even to left half, odd to right half.
        std::sort(nums.begin(), nums.end(), [](int a, int b) { return a % 2 < b % 2; });

        size_t n = nums.size();
        for (size_t i = 1, j = ((n / 2) % 2 == 0 ? (n / 2): (n / 2 + 1)); j < n; i += 2, j += 2) {
            std::swap(nums[i], nums[j]);
        }

        return nums;
    }

    vector<int> sortArrayByParityII(vector<int>& nums) {
        //return linearSwap(nums);
        return sortAndSwap(nums);
    }
};
