class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> bitmaps;
        for (const string& str : arr) {
            int bitmap = 0;
            bool duplicate = false;
            for (char c : str) {
                if (bitmap & (1 << (c - 'a'))) {
                    duplicate = true;
                    continue;
                }
                bitmap |= (1 << (c - 'a'));
            }
            if (!duplicate) {
                bitmaps.push_back(bitmap);
            }
        }
        int n = bitmaps.size();

        std::function<int(int ,int)> dfs = [&](int i, int bitmap) {
            if (i == n) {
                return __builtin_popcount(bitmap);
            }

            int ret1 = dfs(i + 1, bitmap);
            int ret2 = bitmap & bitmaps[i] ? __builtin_popcount(bitmap) : dfs(i + 1, bitmap | bitmaps[i]);
            return std::max(ret1, ret2);
        };

        return dfs(0, 0);
    }
};
