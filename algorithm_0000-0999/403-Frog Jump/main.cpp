class Solution {
public:
    bool btmupDP(vector<int>& stones) {
        int n = stones.size();

        unordered_map<int, int> pos2idx;
        for (int i = 0; i < n; ++i) {
            pos2idx[stones[i]] = i;
        }

        // dp[i][j]: whether the frog can jump from stones[i] to stones[j];
        bool dp[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i <= j; ++i) {
                if (!dp[i][j]) {
                    continue;
                }

                int diff = stones[j] - stones[i];
                if (0 < diff - 1 && pos2idx.find(stones[j] + diff - 1) != pos2idx.end()) {
                    dp[j][pos2idx[stones[j] + diff - 1]] = true;
                }
                if (0 < diff && pos2idx.find(stones[j] + diff) != pos2idx.end()) {
                    dp[j][pos2idx[stones[j] + diff]] = true;
                }
                if (pos2idx.find(stones[j] + diff + 1) != pos2idx.end()) {
                    dp[j][pos2idx[stones[j] + diff + 1]] = true;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (dp[i][n - 1]) {
                return true;
            }
        }

        return false;
    }

    int topdnDFS(vector<int>& stones) {
        int n = stones.size();

        unordered_map<int, int> pos2idx;
        for (int i = 0; i < n; ++i) {
            pos2idx[stones[i]] = i;
        }

        bool failed[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                failed[i][j] = false;;
            }
        }

        // f(i, j): whether the frog can jump from stones[i] to stones[j];
        std::function<bool(int, int)> f = [&](int i, int j) {
            if (j == n - 1) {
                return true;
            }

            if (failed[i][j]) {
                return false;
            }


            int diff = stones[j] - stones[i];
            if (0 < diff - 1 && pos2idx.find(stones[j] + diff - 1) != pos2idx.end()) {
                if (f(j, pos2idx[stones[j] + diff - 1])) {
                    return true;
                }
            }
            if (0 < diff && pos2idx.find(stones[j] + diff) != pos2idx.end()) {
                if (f(j, pos2idx[stones[j] + diff])) {
                    return true;
                }
            }
            if (pos2idx.find(stones[j] + diff + 1) != pos2idx.end()) {
                if (f(j, pos2idx[stones[j] + diff + 1])) {
                    return true;
                }
            }

            failed[i][j] = true;
            return false;
        };

        return f(0, 0);
    }

    bool canCross(vector<int>& stones) {
        //return btmupDP(stones);
        return topdnDFS(stones);
    }
};
