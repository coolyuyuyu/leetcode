class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }

        vector<int> cache(1 << maxChoosableInteger, 2); // 2: not visited
        std::function<bool(int, int)> dfs = [&](int state, int sum) {
            if (cache[state] != 2) {
                return cache[state];
            }

            for (int i = 1; i <= maxChoosableInteger; ++i) {
                if ((state >> (i - 1)) & 1) { continue; }
                if (sum + i >= desiredTotal) { return cache[state] = true; }
                if (dfs(state | (1 << (i - 1)), sum + i) == false) {
                    return cache[state] = true;
                }
            }

            return cache[state] = false;
        };

        return dfs(0, 0);
    }
};
