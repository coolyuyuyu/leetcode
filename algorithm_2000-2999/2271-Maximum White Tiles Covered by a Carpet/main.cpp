class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n = tiles.size();

        std::sort(tiles.begin(), tiles.end());

        int presums[n];
        for (int i = 0; i < n; ++i) {
            presums[i] = (i > 0 ? presums[i - 1] : 0) + (tiles[i][1] - tiles[i][0] + 1);
        }

        int ret = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && tiles[i][0] + carpetLen - 1 >= tiles[j][1]) {
                ++j;
            }

            int cntTiles = 0;
            if (j > i) {
                cntTiles += presums[j - 1] - (i > 0 ? presums[i - 1] : 0);
            }
            if (j < n) {
                cntTiles += std::max(0, tiles[i][0] + carpetLen - 1 - tiles[j][0] + 1);
            }

            ret = std::max(ret, cntTiles);
        }

        return ret;
    }
};
