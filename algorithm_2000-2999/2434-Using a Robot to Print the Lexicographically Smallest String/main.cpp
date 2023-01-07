class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();

        vector<char> suffix(n);
        suffix[n - 1] = s[n - 1];
        for (int i = n - 1; 0 < i--;) {
            suffix[i] = std::min(s[i], suffix[i + 1]);
        }

        string t;

        stack<char> stk;
        for (size_t i = 0; i < n || !stk.empty();) {
            if (i < n && (stk.empty() || suffix[i] < stk.top())) {
                stk.push(s[i]);
                ++i;
            }
            else {
                t.push_back(stk.top());
                stk.pop();
            }
        }

        return t;
    }
};
