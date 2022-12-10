class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        size_t n = vals.size();

        vector<int> neighbors[n];
        for (const auto& edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }

        int ret = INT_MIN;
        for (int node = 0; node < n; ++node) {
            int sum = vals[node];

            priority_queue<int, vector<int>, std::greater<int>> minHeap;
            for (int neighbor : neighbors[node]) {
                if (vals[neighbor] <= 0) {
                    continue;
                }

                if (minHeap.size() < k) {
                    minHeap.push(vals[neighbor]);
                }
                else if (minHeap.top() < vals[neighbor]) {
                    minHeap.pop();
                    minHeap.push(vals[neighbor]);
                }
            }
            while (!minHeap.empty()) {
                sum += minHeap.top();
                minHeap.pop();
            }

            ret = std::max(ret, sum);
        }

        return ret;
    }
};
