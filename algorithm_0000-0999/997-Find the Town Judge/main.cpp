class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int in[n + 1], out[n + 1];
        std::fill(in, in + n + 1, 0);
        std::fill(out, out + n + 1, 0);

        for (const auto& t : trust) {
            ++in[t[1]];
            ++out[t[0]];
        }

        for (int i = 1; i <= n; ++i) {
            if (in[i] == n - 1 && out[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};
