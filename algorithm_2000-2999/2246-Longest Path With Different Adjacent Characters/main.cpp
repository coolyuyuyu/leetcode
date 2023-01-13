class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> degrees(n, 0);
        vector<vector<int>> childs(n);
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                continue;
            }

            ++degrees[parent[i]];
            childs[parent[i]].push_back(i);
        }

        queue<int> nodes;
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 0) {
                nodes.push(i);
            }
        }

        vector<int> longestVerticalLens(n, 0);
        int ret = 0;
        while (!nodes.empty()) {
            int i = nodes.front();
            nodes.pop();

            int lenA = 0, lenB = 0;
            for (int child : childs[i]) {
                if (s[child] != s[i]) {
                    if (lenA <= longestVerticalLens[child]) {
                        lenB = lenA;
                        lenA = longestVerticalLens[child];
                    }
                    else if (lenB < longestVerticalLens[child]) {
                        lenB = longestVerticalLens[child];
                    }
                }
            }
            longestVerticalLens[i] = 1 + lenA;
            ret = std::max({ret, 1 + lenA, 1 + lenA + lenB});

            if (parent[i] == -1) {
                continue;
            }
            if (--degrees[parent[i]] == 0) {
                nodes.push(parent[i]);
            }
        }

        return ret;
    }
};
