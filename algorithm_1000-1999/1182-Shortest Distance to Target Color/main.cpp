class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> distances(3, vector<int>(colors.size(), -1));

        // scan forward
        size_t rhtMost[3] = {0, 0, 0};
        for (size_t i = 0; i < colors.size(); ++i) {
            int color = colors[i] - 1;
            for (size_t j = rhtMost[color]; j <= i ; ++j) {
                distances[color][j] = i - j;
            }
            rhtMost[color] = i + 1;
        }

        // scan backward
        size_t lftMost[3] = {colors.size(), colors.size(), colors.size()};
        for (size_t i = colors.size(); 0 < i--;) {
            int color = colors[i] - 1;
            for (size_t j = lftMost[color]; i < j--;) {
                if (distances[color][j] == -1 || (j - i) < distances[color][j]) {
                    distances[color][j] = j - i;
                }
            }
            lftMost[color] = i;
        }

        vector<int> ans;
        for (const vector<int>& query : queries) {
            ans.push_back(distances[query[1] - 1][query[0]]);
        }

        return ans;
    }
};
