class Solution {
public:
    int countChilds(const vector<vector<int>>& nexts, int node, int parent, int seats, long long & ans) {
        int totalChildCnt = 0;
        for (int child : nexts[node]) {
            if (child == parent) {
                continue;
            }

            int childCnt = countChilds(nexts, child, node, seats, ans) + 1;
            ans += (childCnt / seats) + (childCnt % seats ? 1 : 0);
            totalChildCnt += childCnt;
        }

        return totalChildCnt;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> nexts(n);
        for (const auto& road : roads) {
            nexts[road[0]].push_back(road[1]);
            nexts[road[1]].push_back(road[0]);
        }

        long long ans = 0;
        countChilds(nexts, 0, -1, seats, ans);
        return ans;
    }
};
