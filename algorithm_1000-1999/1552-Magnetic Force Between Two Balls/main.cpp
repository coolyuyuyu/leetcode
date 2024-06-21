class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        std::sort(position.begin(), position.end());
        std::function<bool(int)> checkOk = [&](int minForce) {
            for (int i = 0, cnt = 1; i < n;) {
                int j = i;
                while (j < n && position[j] - position[i] < minForce) {
                    ++j;
                }
                if (j == n) {
                    break;
                }

                if (++cnt >= m) {
                    return true;
                }

                i = j;
            }

            return false;
        };

        int lo = 1, hi = position.back() - position.front();
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
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
