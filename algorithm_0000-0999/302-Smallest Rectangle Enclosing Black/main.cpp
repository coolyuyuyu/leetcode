class Solution {
public:
    // Time: O(MN)
    int byBruteForce(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image.empty() ? 0 : image[0].size();

        int lft = INT_MAX, rht = INT_MIN, top = INT_MAX, btm = INT_MIN;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (image[r][c] == '0') { continue; }
                lft = std::min(lft, c);
                rht = std::max(rht, c);
                top = std::min(top, r);
                btm = std::max(btm, r);
            }
        }

        return (rht - lft + 1) * (btm - top + 1);
    }

    // Time: O(MN)
    int byBruteBFS(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image.empty() ? 0 : image[0].size();
        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        queue<pair<int, int>> q;
        image[x][y] = '0';
        q.emplace(x, y);

        int lft = INT_MAX, rht = INT_MIN, top = INT_MAX, btm = INT_MIN;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            lft = std::min(lft, c);
            rht = std::max(rht, c);
            top = std::min(top, r);
            btm = std::max(btm, r);

            for (const auto& [dr, dc] : dirs) {
                int x = r + dr, y = c + dc;
                if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                if (image[x][y] == '0') { continue; }

                image[x][y] = '0';
                q.emplace(x, y);
            }
        }

        return (rht - lft + 1) * (btm - top + 1);
    }

    // Time: O(MlogN + NlogM)
    int byBinarySearch(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image.empty() ? 0 : image[0].size();
        std::function<bool(int)> checkRow = [&](int r) {
            for (int c = 0; c < n; ++c) {
                if (image[r][c] == '1') { return true; }
            }
            return false;
        };
        std::function<bool(int)> checkCol = [&](int c) {
            for (int r = 0; r < m; ++r) {
                if (image[r][c] == '1') { return true; }
            }
            return false;
        };

        int lft = [&]() {
            int lo = 0, hi = y;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (checkCol(mid)) {
                    hi = mid;
                }
                else {
                    lo = mid + 1;
                }
            }
            return lo;
        }();
        int rht = [&]() {
            int lo = y, hi = n - 1;
            while (lo < hi) {
                int mid = hi - (hi - lo) / 2;
                if (checkCol(mid)) {
                    lo = mid;
                }
                else {
                    hi = mid - 1;
                }
            }
            return lo;
        }();
        int top = [&]() {
            int lo = 0, hi = x;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (checkRow(mid)) {
                    hi = mid;
                }
                else {
                    lo = mid + 1;
                }
            }
            return lo;
        }();
        int btm = [&]() {
            int lo = x, hi = m - 1;
            while (lo < hi) {
                int mid = hi - (hi - lo) / 2;
                if (checkRow(mid)) {
                    lo = mid;
                }
                else {
                    hi = mid - 1;
                }
            }
            return lo;
        }();

        return (rht - lft + 1) * (btm - top + 1);
    }

    int minArea(vector<vector<char>>& image, int x, int y) {
        //return byBruteForce(image, x, y);
        //return byBruteBFS(image, x, y);
        return byBinarySearch(image, x, y);
    }
};
