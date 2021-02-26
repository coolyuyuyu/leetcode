class Solution {
public:
    string removeDuplicates(string s, int k) {
        assert(2 <= k);

        stack<pair<char, int>> stk;
        for (char c : s) {
            if (stk.empty() || stk.top().first != c) {
                stk.emplace(c, 0);
            }
            ++stk.top().second;

            while (!stk.empty() && k <= stk.top().second) {
                stk.top().second -= k;
                if (stk.top().second == 0) {
                    stk.pop();
                }
            }
        }

        string str;
        while (!stk.empty()) {
            str.append(stk.top().second, stk.top().first);
            stk.pop();
        }
        reverse(str.begin(), str.end());

        return str;
    }
};