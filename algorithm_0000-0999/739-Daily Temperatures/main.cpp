class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> days(T.size());

        stack<pair<int, size_t>> stk; // temperature, index
        for (size_t i = 0; i < T.size(); ++i) {
            while (!stk.empty() && stk.top().first < T[i]) {
                days[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.emplace(T[i], i);
        }

        return days;
    }
};