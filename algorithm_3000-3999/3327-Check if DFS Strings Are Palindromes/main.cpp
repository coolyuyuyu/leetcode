class Solution {
public:
    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = parent.size();

        vector<int> childs[n];
        for (int c = 0; c < n; ++c) {
            int p = parent[c];
            if (p == -1) { continue; }
            childs[p].push_back(c);
        }

        pair<int, int> boundaries[n];
        string t = "*";
        std::function<void(int)> postorder = [&](int cur) {
            int lft = t.size();
            for (int nxt : childs[cur]) {
                postorder(nxt);
            }
            int rht = t.size();
            t += s[cur];
            t += "*";

            boundaries[cur] = {lft, rht};
        };
        postorder(0);

        int m = t.size();
        // p[i]: the longest extend radius of palindromic substring from t and center at i
        int p[m];
        for (int i = 0, maxRht = -1, maxCtr = -1; i < m; ++i) {
            p[i] = 0;
            if (i < maxRht) {
                int j = 2 * maxCtr - i;
                p[i] = std::min(p[j], maxRht - i);
            }
            while (0 <= i - p[i] - 1 && i + p[i] + 1 < m && t[i - p[i] - 1] == t[i + p[i] + 1]) {
                ++p[i];
            }

            if (i + p[i] > maxRht) {
                maxCtr = i;
                maxRht = i + p[i];
            }
        }

        vector<bool> ret(n);
        for (int i = 0; i < n; ++i) {
            const auto& [lft, rht] = boundaries[i];
            int mid = lft + (rht - lft) / 2;
            int len = rht - lft + 1;
            int extendR = (len - 1) / 2;

            ret[i] = (p[mid] >= extendR);
        }

        return ret;
    }
};
