class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int ret = 0;
        for (int i = 0, n = weight.size(); i < n;) {
            int mx = 0;
            int j = i;
            for (; j < n; ++j) {
                mx = std::max(mx, weight[j]);
                if (mx > weight[j]) {
                    ++ret;
                    break;
                }
            }
            i = j + 1;
        }

        return ret;
    }
};
