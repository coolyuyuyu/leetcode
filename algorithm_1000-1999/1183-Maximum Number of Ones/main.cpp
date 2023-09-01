class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<int> submtx(sideLength * sideLength, 0);
        for (int r = 0; r < height; ++r) {
            for (int c = 0; c < width; ++c) {
                int x = r % sideLength, y = c % sideLength;
                ++submtx[x * sideLength + y];
            }
        }

        std::sort(submtx.rbegin(), submtx.rend());

        int ret = 0;
        for (int i = 0; i < maxOnes; ++i) {
            ret += submtx[i];
        }

        return ret;
    }
};
