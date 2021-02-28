class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stk;
        for (int i = 0; i < nums.size(); ++i) {
            while (!stk.empty() && nums[i] < stk.back() && (k < (stk.size() + nums.size() - i))) {
                stk.pop_back();
            }
            stk.push_back(nums[i]);
        }

        return vector<int>(stk.begin(), stk.begin() + k);
    }
};