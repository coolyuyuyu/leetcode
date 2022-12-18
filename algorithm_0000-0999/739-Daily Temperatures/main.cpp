class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);

        stack<pair<int, int>> stk; // <temperature, index>
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stk.empty() && stk.top().first < temperatures[i]) {
                ret[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.emplace(temperatures[i], i);
        }

        return ret;
    }
};
