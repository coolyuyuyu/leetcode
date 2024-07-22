class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();

        int indexes[n];
        std::iota(indexes, indexes + n, 0);
        std::sort(indexes, indexes + n, [&](int idx1, int idx2){ return heights[idx1] > heights[idx2]; });

        vector<string> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = names[indexes[i]];
        }

        return ret;
    }
};
