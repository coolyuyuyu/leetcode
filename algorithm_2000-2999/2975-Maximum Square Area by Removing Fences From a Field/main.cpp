class Solution {
public:
    int M = 1e9 + 7;

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        std::sort(hFences.begin(), hFences.end());
        hFences.insert(hFences.begin(), 1);
        hFences.insert(hFences.end(), m);

        unordered_set<int> sides;
        for (int i = 0; i < hFences.size(); ++i) {
            for (int j = i + 1; j < hFences.size(); ++j) {
                sides.insert(hFences[j] - hFences[i]);
            }
        }

        std::sort(vFences.begin(), vFences.end());
        vFences.insert(vFences.begin(), 1);
        vFences.insert(vFences.end(), n);

        int maxSide = -1;
        for (int i = 0; i < vFences.size(); ++i) {
            for (int j = i + 1; j < vFences.size(); ++j) {
                int side = vFences[j] - vFences[i];
                if (sides.find(side) != sides.end()) {
                    maxSide = std::max(maxSide, side);
                }
            }
        }

        return maxSide == -1 ? -1 : (1LL * maxSide * maxSide) % M;
    }
};
