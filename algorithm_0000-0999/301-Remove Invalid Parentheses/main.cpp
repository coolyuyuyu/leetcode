class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ret;

        std::function<void(string&, int, int)> dfs = [&](string& cur, int i, int cnt) {
            if (cnt < 0) { return; }
            else if (i >= s.size()) {
                if (cnt != 0) { return; }
                else if (ret.empty() || cur.size() == ret[0].size()) {
                    ret.push_back(cur);
                }
                else if (cur.size() > ret[0].size()) {
                    ret.clear();
                    ret.push_back(cur);
                }

                return;
            }

            if (s[i] != '(' && s[i] != ')') {
                cur += s[i];
                dfs(cur, i + 1, cnt);
                cur.pop_back();
            }
            else {
                cur += s[i];
                dfs(cur, i + 1, cnt + (s[i] == '(' ? 1 : -1));
                cur.pop_back();

                if (cur.empty() || cur.back() != s[i]) {
                    dfs(cur, i + 1, cnt);
                }
            }
        };
        string cur;
        dfs(cur, 0, 0);

        return ret;
    }
};
