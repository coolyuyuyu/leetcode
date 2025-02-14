class Solution {
public:
    long long maxScore(vector<int>& points, int m) {
        int n = points.size();
        std::function<bool(long long)> checkOk = [&](long long target) {
            long long moves = 1;
            long long point = points[0];
            for (int i = 0; i + 1 < n; ++i) {
                if (point >= target) {
                    moves += 1;
                    if (moves > m) {
                        return false;
                    }
                    point = points[i + 1];
                }
                else {
                    long long step = (target - point - 1) / points[i] + 1;
                    if (i == n - 2 && (moves + step * 2 <= m) && (points[i + 1] * step >= target)) {
                        return true;
                    }
                    moves += step * 2 + 1;
                    if (moves > m) {
                        return false;
                    }
                    point = points[i + 1] * (step + 1);
                }
            }

            if (point >= target) {
                return true;
            }
            int step = (target - point - 1) / points[n - 1] + 1;
            moves += step * 2;
            return moves <= m;
        };

        long long lo = 0, hi = 1e15;
        while (lo < hi) {
            long long mid = hi - (hi - lo) / 2;
            if (checkOk(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
