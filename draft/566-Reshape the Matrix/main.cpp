class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int count = nums.size() * (nums.empty() ? 0 : nums.front().size());
        
        if ((r * c) != count) {
            return nums;
        }
        int x = 0, y = 0;
        vector<vector<int>> result(r, vector<int>(c));
        for (vector<vector<int>>::const_iterator rowIter = nums.begin(); rowIter != nums.end(); ++rowIter) {
            for (vector<int>::const_iterator iter = rowIter->begin(); iter != rowIter->end(); ++iter) {
                result[x][y] = *iter;
                ++y;
                if (y == c) {
                    ++x;
                    y = 0;
                }
            }
        }

        return result;
    }
};