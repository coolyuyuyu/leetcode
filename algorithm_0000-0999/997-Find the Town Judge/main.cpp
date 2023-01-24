class Solution {
public:
    // Time: O(n)
    int checkInOutDegree(int n, vector<vector<int>>& trust) {
        if ((trust.size() + 1) < n) {
            return -1;
        }

        vector<pair<int, int>> degrees(n); // <in, out>
        for (const auto& edge : trust) {
            ++degrees[edge[1] - 1].first;
            ++degrees[edge[0] - 1].second;
        }

        for (int i = 0; i < n; ++i) {
            const auto& [in, out] = degrees[i];
            if (in == (n - 1) && out == 0) {
                return i + 1;
            }
        }

        return -1;
    }

    // Variation of in/out degree
    int checkScore(int n, vector<vector<int>>& trust) {
        if ((trust.size() + 1) < n) {
            return -1;
        }

        vector<int> scores(n);
        for (const auto& edge : trust) {
            ++scores[edge[1] - 1];
            --scores[edge[0] - 1];
        }

        for (int i = 0; i < n; ++i) {
            if (scores[i] == (n - 1)) {
                return i + 1;
            }
        }

        return -1;
    }

    int findJudge(int n, vector<vector<int>>& trust) {
        //return checkInOutDegree(n, trust);
        return checkScore(n, trust);
    }
};
