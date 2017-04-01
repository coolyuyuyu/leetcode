class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> lists;
        lists.reserve(numRows);

        if (0 < numRows) {
            vector<int> nums(1, 1);
            lists.push_back(nums);
        }

        for (int i = 1; i < numRows; ++i) {
            int count = i + 1;
            vector<int> nums;
            nums.reserve(count);
            nums.push_back(1);
            const vector<int>& prevNums = lists.back();
            for (size_t j = 0; j < prevNums.size() - 1; ++j) {
                nums.push_back(prevNums[j] + prevNums[j + 1]);
            }
            nums.push_back(1);
            lists.push_back(nums);
        }
        return lists;
    }
};