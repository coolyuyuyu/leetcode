class Solution {
public:
    int minOperations(string s, int k) {
        // cur0: number of 0 in s
        // cur1: number of 1 in s
        // n: length of s
        //
        // x:      number 0 is going to be flip as 1 in one step
        // k - x:  number 1 is going to be flip as 0 in one step
        //
        // ------
        // nxt0: number of 0 after 1 step
        //     : cur0 - x + (k - x) = cur0 + k - 2x
        //
        // ------
        // x cannot greater than cur0
        // => x <= std::min(cur0, k)
        //
        // k - x cannot greater than cur1
        // => k - x <= n - cur0
        // => x >= std::max(k + cur0 - n, 0)
        //
        // => x ∈ [std::max(k + cur0 - n, 0), std::min(cur0, k)]
        //
        // ------
        // min nxt0
        //     => max x
        //     => cur0 + k - 2x
        //     => cur0 + k - 2 * std::min(cur0, k)
        //
        // max nxt0
        //     => min x
        //     => cur0 + k - 2x
        //     => cur0 + k - 2 * std::max(k + cur0 - n, 0)
        //
        // ------
        // nxt0 = cur0 + k - 2x
        // => nxt0 ≡ cur0 + k (mod2)

        int n = s.size();
        int cur0 = std::count(s.begin(), s.end(), '0');
        if (cur0 == 0) { return 0; }

        vector<set<int>> unusedVec(2);
        for (int i = 0; i <= n; ++i) {
            unusedVec[i & 1].insert(i);
        }

        int src = cur0;
        queue<pair<int, int>> q;
        q.emplace(src, 0);
        unusedVec[src & 1].erase(src);
        while (!q.empty()) {
            auto [cur0, step] = q.front();
            q.pop();

            if (cur0 == 0) {
                return step;
            }

            int minX = std::max(k + cur0 - n, 0), maxX = std::min(cur0, k);
            int minNxt0 = cur0 + k - 2 * maxX, maxNxt0 = cur0 + k - 2 * minX;

            auto& unuseds = unusedVec[(cur0 + k) & 1];
            vector<int> toRemove;
            for (auto itr = unuseds.lower_bound(minNxt0); itr != unuseds.end() && *itr <= maxNxt0; ++itr) {
                toRemove.push_back(*itr);
            }
            for (int nxt0 : toRemove) {
                unuseds.erase(nxt0);
                q.emplace(nxt0, step + 1);
            }
        }

        return -1;
    }
};
