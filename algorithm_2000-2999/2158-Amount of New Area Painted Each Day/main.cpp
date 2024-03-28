class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        vector<pair<int, vector<pair<int, bool>>>> diffs;
        map<int, vector<pair<int, bool>>> m;
        for (int i = 0; i < paint.size(); ++i) {
            const auto& p = paint[i];
            int lft = p[0], rht = p[1];
            m[lft].emplace_back(i, false);
            m[rht].emplace_back(i, true);
        }
        vector<pair<int, vector<pair<int, bool>>>> diffArr(m.begin(), m.end());

        vector<int> ret(paint.size(), 0);

        set<int> s;
        for (int x = 0; x + 1 < diffArr.size(); ++x) {\
            const auto& [bgn, diffs] = diffArr[x];
            for (const auto& [i, done] : diffs) {
                if (done) {
                    s.erase(i);
                }
                else {
                    s.insert(i);
                }
            }

            if (!s.empty()) {
                int i = *s.begin();
                int end = diffArr[x + 1].first;
                ret[i] += end - bgn;
            }
        }

        return ret;
    }
};
