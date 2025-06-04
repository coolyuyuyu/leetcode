class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        int dists1[n], dists2[n];
        std::fill(dists1, dists1 + n, INT_MAX);
        std::fill(dists2, dists2 + n, INT_MAX);
        std::function<void(int, int[])> computeDists = [&](int node, int dists[]) {
            for (int dist = 0; node != -1 && dists[node] == INT_MAX; node = edges[node], ++dist) {
                dists[node] = dist;
            }
        };
        computeDists(node1, dists1);
        computeDists(node2, dists2);

        int minDist = INT_MAX;
        int ret = -1;
        for (int i = 0; i < n; ++i) {
            int dist = std::max(dists1[i], dists2[i]);
            if (dist < minDist) {
                minDist = dist;
                ret = i;
            }
        }

        return ret;
    }
};
