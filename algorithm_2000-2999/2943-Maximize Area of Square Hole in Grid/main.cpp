class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        std::function<int(const vector<int>&)> f = [](const vector<int>& bars) {
            int maxCnt = 0;
            for (int i = 0, cnt = 0; i < bars.size(); ++i) {
                if (i > 0 && bars[i - 1] + 1 == bars[i]) {
                    ++cnt;
                }
                else {
                    cnt = 1;
                }
                maxCnt = std::max(maxCnt, cnt);
            }

            return maxCnt + 1;
        };

        std::sort(hBars.begin(), hBars.end());
        std::sort(vBars.begin(), vBars.end());
        int s = std::min(f(hBars), f(vBars));
        return s * s;
    }
};
