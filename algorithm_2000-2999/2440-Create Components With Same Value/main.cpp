class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> graph(n);
        vector<int> inDegrees(n, 0);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            ++inDegrees[edge[0]];
            ++inDegrees[edge[1]];
        }
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<int> targets;
        for (int i = 1, last = sqrt(total); i <= last; ++i) {
            if ((total % i) != 0) {
                continue;
            }

            int j = total / i;
            targets.push_back(i);
            if (i != j) {
                targets.push_back(j);
            }
        }
        std::sort(targets.begin(), targets.end());

        for (int target : targets) {
            vector<int> sums(nums);
            vector<int> degrees(inDegrees);
            vector<bool> visited(n, false);
            queue<int> q;
            for (int i = 0; i < n; ++i) {
                if (degrees[i] <= 1) {
                    visited[i] = true;
                    q.push(i);
                }
            }

            bool splittable = true;
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                if (target < sums[node]) {
                    splittable = false;
                    break;
                }
                if (target == sums[node]) {
                    sums[node] = 0;
                }

                for (int neighbor : graph[node]) {
                    if (visited[neighbor]) {
                        continue;
                    }
                    sums[neighbor] += sums[node];
                    if (--degrees[neighbor] <= 1) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            if (splittable) {
                return total / target - 1;
            }
        }

        return 0;
    }
};
