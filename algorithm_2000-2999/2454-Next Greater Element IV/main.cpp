class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<int> ret(nums.size(), -1);

        stack<size_t> stk1, stk2;
        for (size_t i = 0; i < nums.size(); ++i) {
            while (!stk2.empty() && nums[stk2.top()] < nums[i]) {
                ret[stk2.top()] = nums[i];
                stk2.pop();
            }

            vector<size_t> tmp;
            while (!stk1.empty() && nums[stk1.top()] < nums[i]) {
                tmp.push_back(stk1.top());
                stk1.pop();
            }
            for (size_t i = tmp.size(); 0 < i--;) {
                stk2.push(tmp[i]);
            }

            stk1.push(i);
        }

        return ret;
    }
};
