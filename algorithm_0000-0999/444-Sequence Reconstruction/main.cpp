class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, unordered_set<int>> graph;
        unordered_map<int, int> inCounts;
        for (const vector<int>& seq : seqs) {
            if (seq.size() == 1) {
                inCounts.emplace(seq.front(), 0);
            }
            else if (1 < seq.size()) {
                for (size_t i = 0; i + 1 < seq.size(); ++i) {
                    inCounts.emplace(seq[i], 0);
                    if (graph[seq[i]].emplace(seq[i + 1]).second) {
                        ++inCounts[seq[i + 1]];
                    }
                }
            }
        }

        queue<int> q; {
            for (const pair<int, int>& p : inCounts) {
                if (p.second == 0) {
                    q.emplace(p.first);
                }
            }
        }

        size_t index = 0;
        while (!q.empty()) {
            if (q.size() > 1) {
                return false;
            }

            int node = q.front();
            q.pop();
            if (org.size() <= index) {
                return false;
            }

            if (org[index++] != node) {
                return false;
            }

            for (int neighbor : graph[node]) {
                if (--inCounts[neighbor] == 0) {
                    q.emplace(neighbor);
                }
            }
        }

        return index == org.size() && index == graph.size();
    }
};