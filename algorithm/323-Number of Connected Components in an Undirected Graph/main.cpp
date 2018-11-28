class Solution {
public:
    int countComponentsMultimapAsAdjList(int n, vector<pair<int, int>>& edges) {
        vector<bool> visited(n, false);
        int count = 0;

        unordered_multimap<int, int> adjLists;
        for (const pair<int, int>& edge : edges) {
            adjLists.emplace(edge.first, edge.second);
            adjLists.emplace(edge.second, edge.first);
        }

        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }

            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int index1 = q.front();
                q.pop();

                visited[index1] = true;

                auto range = adjLists.equal_range(index1);
                for (auto itr = range.first; itr != range.second; ++itr) {
                    int index2 = itr->second;
                    if (visited[index2]) {
                        continue;
                    }

                    q.push(index2);
                }
            }

            ++count;
        }

        return count;
    }

    int countComponents2DVectorAsAdjList(int n, vector<pair<int, int>>& edges) {
        vector<bool> visited(n, false);
        int count = 0;

        vector<vector<int>> adjLists(n);
        for (const pair<int, int>& edge : edges) {
            adjLists[edge.first].push_back(edge.second);
            adjLists[edge.second].push_back(edge.first);
        }

        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }

            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int index1 = q.front();
                q.pop();

                visited[index1] = true;

                for (int index2 : adjLists[index1]) {
                    if (visited[index2]) {
                        continue;
                    }

                    q.push(index2);
                }
            }

            ++count;
        }

        return count;
    }

    int countComponents(int n, vector<pair<int, int>>& edges) {
        //return countComponentsMultimapAsAdjList(n, edges);
        return countComponents2DVectorAsAdjList(n, edges);
    }
};