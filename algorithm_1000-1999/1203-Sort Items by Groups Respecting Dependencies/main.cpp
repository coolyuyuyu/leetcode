class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        std::function<vector<int>(vector<int>&, vector<vector<int>>&, vector<int>& in)> topologicalSort = [](vector<int>& nodes, vector<vector<int>>& graph, vector<int>& in) {
            vector<int> ret;

            queue<int> q;
            for (int node : nodes) {
                if (in[node] == 0) {
                    q.push(node);
                }
            }
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();

                ret.push_back(cur);

                for (int nxt : graph[cur]) {
                    if (--in[nxt] == 0) {
                        q.push(nxt);
                    }
                }
            }

            return ret;
        };

        vector<vector<int>> graph;
        vector<int> in;


        vector<vector<int>> groupNodes(m);
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = m++;
                groupNodes.emplace_back();
            }
            groupNodes[group[i]].push_back(i);
        }

        // build graph within group
        graph.assign(n, {});
        in.assign(n, 0);
        for (int to = 0; to < n; ++to) {
            for (int from : beforeItems[to]) {
                if (group[from] == group[to]) {
                    graph[from].push_back(to);
                    ++in[to];
                }
            }
        }

        for (auto& nodes : groupNodes) {
            int n = nodes.size();
            nodes = topologicalSort(nodes, graph, in);
            if (nodes.size() != n) {
                return {};
            }
        }

        // build graph among group
        graph.assign(m, {});
        in.assign(m, 0);
        for (int to = 0; to < n; ++to) {
            for (int from : beforeItems[to]) {
                if (group[from] != group[to]) {
                    graph[group[from]].push_back(group[to]);
                    ++in[group[to]];
                }
            }
        }

        vector<int> groups(m);
        std::iota(groups.begin(), groups.end(), 0);
        groups = topologicalSort(groups, graph, in);
        if (groups.size() != m) {
            return {};
        }

        vector<int> ret;
        for (int g :groups) {
            ret.insert(ret.end(), groupNodes[g].begin(), groupNodes[g].end());
        }

        return ret;
    }
};
