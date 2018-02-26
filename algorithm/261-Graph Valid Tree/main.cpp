class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n != edges.size() + 1) {
            return false;
        }

        vector<int> parents(n);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }

        for (const pair<int, int>& edge : edges) {
            int a = edge.first;
            while (parents[a] != a) {
                a = parents[a];
            }

            int b = edge.second;
            while (parents[b] != b) {
                b = parents[b];
            }

            if (a == b) {
                return false;
            }

            parents[a] = b;
        }

        return true;
    }
};