class Solution {
public:
    int checkInOutDegree(int n, vector<vector<int>>& trust) {
        if ((trust.size() + 1) < n) {
            return -1;
        }

        vector<pair<int, int>> degrees(n); // vector of <indegree, outdegree>
        for (const auto& t : trust) {
            degrees[t[0] - 1].second += 1;
            degrees[t[1] - 1].first += 1;
        }

        for (int i = 0; i < degrees.size(); ++i) {
            if (degrees[i].first + 1 == n && degrees[i].second == 0) {
                return i + 1;
            }
        }

        return -1;
    }

    int checkScore(int n, vector<vector<int>>& trust) {
        if ((trust.size() + 1) < n) {
            return -1;
        }

        vector<int> scores(n); // vector of <indegree, outdegree>
        for (const auto& t : trust) {
            scores[t[0] - 1] -= 1;
            scores[t[1] - 1] += 1;
        }

        for (int i = 0; i < scores.size(); ++i) {
            if (scores[i] + 1 == n) {
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
