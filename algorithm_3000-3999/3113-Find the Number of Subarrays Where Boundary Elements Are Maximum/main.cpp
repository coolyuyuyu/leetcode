class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long ret = 0;
        stack<int> stk;
        unordered_map<int, int> cnts;
        for (int num : nums) {
            while (!stk.empty() && stk.top() < num) {
                --cnts[stk.top()];
                stk.pop();
            }
            stk.push(num);
            ++cnts[num];

            ret += cnts[num];
        }

        return ret;
    }
};
