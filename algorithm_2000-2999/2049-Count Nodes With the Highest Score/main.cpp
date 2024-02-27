class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();

        vector<int> childsArr[n];
        for (int i = 1; i < n; ++i) {
            childsArr[parents[i]].push_back(i);
        }

        long long maxScore = 0;
        int maxScoreCnt = 1;
        std::function<int(int)> dfs = [&](int root) {
            int cnt = 1;
            long long score = 1;
            for (int child : childsArr[root]) {
                int childCnt = dfs(child);
                cnt += childCnt;
                score *= childCnt;
            }
            if (root != 0) {
                score *= n - cnt;
            }

            if (score > maxScore) {
                maxScore = score;
                maxScoreCnt = 1;
            }
            else if (score == maxScore) {
                ++maxScoreCnt;
            }

            return cnt;
        };
        dfs(0);

        return maxScoreCnt;
    }
};
