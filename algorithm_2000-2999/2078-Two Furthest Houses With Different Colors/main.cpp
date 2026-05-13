class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ret = -1;
        for (int i = 0, n = colors.size(); i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (colors[i] != colors[j]) {
                    ret = std::max(ret, j - i);
                }
            }
        }

        return ret;
    }
};
