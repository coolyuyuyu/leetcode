class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> nums;
        nums.push_back(1);
        for (int i = 1; i <= rowIndex; ++i) {
            vector<int> tmpNums;
            tmpNums.reserve(nums.size() + 1);
            tmpNums.push_back(1);
            for (size_t j = 0; j < nums.size() - 1; ++j) {
                tmpNums.push_back(nums[j] + nums[j + 1]);
            }
            tmpNums.push_back(1);
            nums.swap(tmpNums);
        }

        return nums;
    }
};