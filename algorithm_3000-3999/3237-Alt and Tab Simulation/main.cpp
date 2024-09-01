class Solution {
public:
    vector<int> simulationResult(vector<int>& windows, vector<int>& queries) {
        int n = windows.size();
        vector<int> ret(n);
        int idx = 0;

        unordered_set<int> used;
        for (int i = queries.size(); 0 < i--;) {
            if (used.insert(queries[i]).second) {
                ret[idx++] = queries[i];
            }
        }

        for (int i = 0; i < windows.size(); ++i) {
            if (used.find(windows[i]) == used.end()) {
                ret[idx++] = windows[i];
            }
        }

        return ret;
    }
};
