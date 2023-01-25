class Solution {
public:
    vector<int> computeDistances(const vector<int>& edges, int src) {
        int n = edges.size();
        vector<int> dists(n, INT_MAX);
        for (int dist = 0; src != -1 && dists[src] == INT_MAX; ++dist) {
            dists[src] = dist;
            src = edges[src];
        }

        return dists;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if (node1 == node2) {
            return node1;
        }

        int n = edges.size();
        vector<int> dists1 = computeDistances(edges, node1), dists2 = computeDistances(edges, node2);

        int target = -1;
        int minDist = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int dist = std::max(dists1[i], dists2[i]);
            if (dist == INT_MAX) {
                continue;
            }

            if (dist < minDist) {
                target = i;
                minDist = dist;
            }
        }

        return target;
    }
};

/*
[9,8,7,0,5,6,1,3,2,2]
 0 1 2 3 4 5 6 7 8 9
 1 -> 8 -> 2 -> 7 -> 3 -> 0 -> 9 -> 2
*/
