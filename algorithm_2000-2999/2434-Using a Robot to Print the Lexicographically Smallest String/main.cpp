class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();

        char sufMin[n];
        sufMin[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            sufMin[i] = std::min(s[i], sufMin[i + 1]);
        }

        stack<char> t;

        string ret;
        for (int i = 0; i < n || !t.empty();) {
            if (i < n && (t.empty() || t.top() > sufMin[i])) {
                t.push(s[i++]);
            }
            else {
                ret.push_back(t.top());
                t.pop();
            }
        }

        return ret;
    }
};
