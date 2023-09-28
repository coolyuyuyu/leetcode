class Solution {
public:
    // Time: O(nlogn)
    vector<int> sortByLastBit(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int num1, int num2) { return (num1 & 1) < (num2 & 1); });
        return nums;
    }

    // Time: O(n)
    vector<int> twopointers(vector<int>& nums) {
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            if (nums[j] % 2 == 0) {
                swap(nums[i++], nums[j]);
            }
        }
        return nums;
    }

    vector<int> sortArrayByParity(vector<int>& nums) {
        //return sortByLastBit(nums);
        return twopointers(nums);
    }
};
