class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n = tiles.size();

        std::sort(tiles.begin(), tiles.end());

        int ret = 0;
        for (int i = 0, j = 0, sum = 0; i < n; ++i) {
            int end = tiles[i][0] + carpetLen - 1;
            for (; j < n && end >= tiles[j][1]; ++j) {
                sum += tiles[j][1] - tiles[j][0] + 1;
            }

            int extra = 0;
            if (j < n && end >= tiles[j][0]) {
                extra += end - tiles[j][0] + 1;
            }

            ret = std::max(ret, sum + extra);

            sum -= tiles[i][1] - tiles[i][0] + 1;
        }

        return ret;
    }
};
