class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        std::function<bool(int)> checkPrime = [](int num) {
            if (num == 1) { return false; }
            for (int i = 2, n = std::sqrt(num); i <= n; ++i) {
                if (num % i == 0) {
                    return false;
                }
            }

            return true;
        };

        unordered_map<int, int> prime2cnt;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                for (const auto& [dr, dc] : dirs) {
                    int num = 0;
                    for (int x = r, y = c; 0 <= x && x < m && 0 <= y && y < n; x += dr, y += dc) {
                        num = num * 10 + mat[x][y];
                        if (num > 10 && checkPrime(num)) {
                            ++prime2cnt[num];
                        }
                    }
                }
            }
        }

        int maxCnt = 0;
        for (const auto& [_, cnt] : prime2cnt) {
            maxCnt = std::max(maxCnt, cnt);
        }
        if (maxCnt == 0) {
            return -1;
        }

        int ret = 0;
        for (const auto& [num, cnt] : prime2cnt) {
            if (cnt < maxCnt) { continue; }
            ret = std::max(ret, num);
        }

        return ret;
    }
};
