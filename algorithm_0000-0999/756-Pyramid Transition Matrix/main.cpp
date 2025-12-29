class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> m;
        for (const string& s : allowed) {
            m[s.substr(0, 2)].push_back(s[2]);
        }

        unordered_set<string> fails;
        std::function<bool(const string&)> dfs = [&](const string& cur) {
            if (cur.size() <= 1) { return true; }
            if (fails.find(cur) != fails.end()) { return false; }

            vector<string> nxts;
            for (int i = 0; i + 1 < cur.size(); ++i) {
                const vector<char>& tops = m[cur.substr(i, 2)];
                if (tops.empty()) {
                    fails.insert(cur);
                    return false;
                }

                vector<string> tmps = std::move(nxts);
                for (char c : tops) {
                    if (tmps.empty()) {
                        nxts.emplace_back(1, c);
                    }
                    else {
                        for (const string& tmp : tmps) {
                            nxts.push_back(tmp + c);
                        }
                    }
                }
            }

            for (const string& nxt : nxts) {
                if (dfs(nxt)) {
                    return true;
                }
            }

            fails.insert(cur);
            return false;
        };

        return dfs(bottom);
    }
};
