class Solution {
public:
    int maxDistance(vector<int>& colors) {
        size_t maxDist = 0;
        for (size_t i = 0; i < colors.size(); ++i) {
            for (size_t j = colors.size(); i + maxDist + 1 < j--;) {
                if (colors[i] != colors[j]) {
                    maxDist = j - i;
                    break;
                }
            }
        }

        return maxDist;
    }
};
