class Solution {
public:
    int n;
    int src;

    int cnts[30005];
    vector<int> graph[30005];

    int dfs1(int cur, int pre) {
        int& cnt = cnts[cur];

        cnt = 1;
        for (int nxt : graph[cur]) {
            if (nxt == pre) { continue;}
            cnt += dfs1(nxt, cur);
        }

        return cnt;
    }

    int dfs2(int cur, int pre) {
        int dist = 0;
        for (int nxt : graph[cur]) {
            if (nxt == pre) { continue;}
            dist += dfs2(nxt, cur);
        }
        dist += cnts[cur] - 1;

        return dist;
    }

    void dfs3(int cur, int pre, vector<int>& ret) {
        for (int nxt : graph[cur]) {
            if (nxt == pre) { continue;}
            ret[nxt] = ret[cur] - cnts[nxt] + (n - cnts[nxt]);
            dfs3(nxt, cur, ret);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        this->src = 0;
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        dfs1(src, -1);

        vector<int> ret(n);
        ret[src] = dfs2(src, -1);
        dfs3(src, -1, ret);

        return ret;
    }
};
