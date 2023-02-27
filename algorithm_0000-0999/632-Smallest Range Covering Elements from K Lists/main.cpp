class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        set<tuple<int, int, int>> s; // num, row, col
        for (int i = 0; i < nums.size(); ++i) {
            s.emplace(nums[i][0], i, 0);
        }

        int minDiff = INT_MAX;
        vector<int> ret;
        while (true) {
            auto [num, row, col] = *s.begin();
            int newDiff = std::get<0>(*s.rbegin()) - num;
            if (newDiff < minDiff) {
                minDiff = newDiff;
                ret = {num, std::get<0>(*s.rbegin())};
            }

            s.erase(s.begin());
            if (nums[row].size() <= (col + 1)) {
                break;
            }

            s.emplace(nums[row][col + 1], row, col + 1);
        }

        return ret;
    }
};
