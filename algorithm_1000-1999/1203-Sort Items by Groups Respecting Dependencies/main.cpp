class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {\
        vector<vector<int>> groupNodes(m);
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = groupNodes.size();
                groupNodes.emplace_back();
            }
            groupNodes[group[i]].push_back(i);
        }
        m = groupNodes.size();

        auto topologicalSort = [](vector<int>& nodes, unordered_map<int, unordered_set<int>>& next, vector<int>& inDegrees) {
            queue<int> q;
            for (int i : nodes) {
                if (inDegrees[i] == 0) {
                    q.push(i);
                }
            }

            vector<int> ret;
            while (!q.empty()) {
                int i = q.front();
                q.pop();

                ret.push_back(i);

                for (int j : next[i]) {
                    if (--inDegrees[j] == 0) {
                        q.push(j);
                    }
                }
            }

            return ret;
        };

        // build dependency within group
        unordered_map<int, unordered_set<int>> next;
        vector<int> inDegrees(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j : beforeItems[i]) {
                if (group[i] != group[j]) { continue; }
                if (next[j].insert(i).second) {
                    ++inDegrees[i];
                }
            }
        }

        // topological sort within group
        vector<vector<int>> groupOrderedNodes(m);
        for (int j = 0; j < m; ++j) {
            groupOrderedNodes[j] = topologicalSort(groupNodes[j], next, inDegrees);
            if (groupOrderedNodes[j].size() != groupNodes[j].size()) {
                return {};
            }
        }

        // build dependency among groups
        next.clear();
        inDegrees.assign(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j : beforeItems[i]) {
                if (group[i] == group[j]) { continue; }
                if (next[group[j]].insert(group[i]).second) {
                    ++inDegrees[group[i]];
                }
            }
        }

        // topological sort among groups
        vector<int> orderedGroups(m);
        std::iota(orderedGroups.begin(), orderedGroups.end(), 0);
        orderedGroups = topologicalSort(orderedGroups, next, inDegrees);
        if (orderedGroups.size() != m) {
            return {};
        }

        vector<int> ret;
        for (int j : orderedGroups) {
            ret.insert(ret.end(), groupOrderedNodes[j].begin(), groupOrderedNodes[j].end());
        }

        return ret;
    }
};
