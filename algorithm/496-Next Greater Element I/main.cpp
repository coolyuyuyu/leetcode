class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> nexts;
        stack<int> stk;
        for (size_t i = 0; i < nums.size(); ++i) {
            while (!stk.empty() && stk.top() < nums[i]) {
                nexts[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(nums[i]);
        }

        while (!stk.empty()) {
            nexts[stk.top()] = -1;
            stk.pop();
        }

        vector<int> result(findNums.size());
        for (size_t i = 0; i < findNums.size(); ++i) {
            result[i] = nexts[findNums[i]];
        }

        return result;
    }
};