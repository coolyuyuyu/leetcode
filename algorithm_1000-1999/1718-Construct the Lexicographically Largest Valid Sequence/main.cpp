class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> seq(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        std::function<bool(int)> dfs = [&](int pos) {
            if (pos >= seq.size()) { return true; }
            if (seq[pos] > 0) { return dfs(pos + 1); }

            for (int d = n; d >= 1; --d) {
                if (used[d]) { continue; }
                if (d > 1 && (pos + d >= seq.size() || seq[pos + d] > 0)) { continue; }

                used[d] = true;
                seq[pos] = d;
                if (d > 1) { seq[pos + d] = d; }

                if (dfs(pos + 1)) {
                    return true;
                }

                seq[pos] = 0;
                if (d > 1) { seq[pos + d] = 0; }
                used[d] = false;
            }

            return false;
        };
        dfs(0);

        return seq;
    }
};
