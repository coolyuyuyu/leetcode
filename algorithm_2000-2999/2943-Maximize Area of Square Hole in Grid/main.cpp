class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        std::function<int(vector<int>&)> f = [](vector<int>& bars) {
            std::sort(bars.begin(), bars.end());

            int maxCnt = 1;
            for (int i = 0, cnt; i < bars.size(); ++i) {
                if (i == 0 || bars[i - 1] + 1 != bars[i]) {
                    cnt = 1;
                }
                else {
                    ++cnt;
                }
                maxCnt = std::max(maxCnt, cnt);
            }

            return maxCnt + 1;
        };

        int x = std::min(f(hBars), f(vBars));
        return x * x;
    }
};
