class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ret;

        std::function<void(string, long, long, int)> dfs = [&](string expr, long val, long last, int idx) {
            if (idx >= num.size()) {
                if (val == target) {
                    ret.push_back(expr);
                }
                return;
            }

            for (int i = idx; i < num.size(); ++i) {
                string nxtOpd = num.substr(idx, i - idx + 1);
                long nxtVal = std::stol(nxtOpd);
                if (nxtOpd.size() > 1 && nxtOpd[0] == '0') { continue; }

                if (idx == 0) {
                    dfs(nxtOpd, nxtVal, nxtVal, i + 1);
                }
                else {
                    dfs(expr + "+" + nxtOpd, val + nxtVal, nxtVal, i + 1);
                    dfs(expr + "-" + nxtOpd, val - nxtVal, -nxtVal, i + 1);
                    dfs(expr + "*" + nxtOpd, val - last + last * nxtVal, last * nxtVal, i + 1);
                }
            }
        };
        dfs("", 0, 0, 0);

        return ret;
    }
};
