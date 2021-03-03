class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> stk({{0, ""}});
        int k = 0;
        for (char c : s) {
            if ('0' <= c && c <= '9') {
                k = k * 10 + c - '0';
            }
            else if (c == '[') {
                stk.emplace(k, "");
                k = 0;
            }
            else if (c == ']') {
                int repeat = stk.top().first;
                string token = stk.top().second;
                stk.pop();

                for (int i = 0; i < repeat; ++i) {
                    stk.top().second += token;
                }
            }
            else {
                stk.top().second.push_back(c);
            }
        }

        return stk.top().second;
    }
};