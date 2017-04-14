class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> stk;
        unordered_map<int, int> m;
        for (size_t i = 0; i < nums.size(); ++i) {
            while (!stk.empty() && stk.top() < nums[i]) {
                m.emplace(stk.top(), nums[i]);
                stk.pop();
            }
            stk.push(nums[i]);
        }

        while (!stk.empty()) {
            m.emplace(stk.top(), -1);
            stk.pop();
        }

        vector<int> result;
        result.reserve(findNums.size());
        for (size_t i = 0; i < findNums.size(); ++i) {
            result.push_back(m[findNums[i]]);
        }

        return result;
    }
};