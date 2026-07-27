class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) {
            return {};
        }

        int idxs[n];
        std::iota(idxs, idxs + n, 0);
        std::sort(idxs, idxs + n, [&](int idx1, int idx2){ return arr[idx1] < arr[idx2]; });

        vector<int> ret(n);
        for (int i = 0, pre = INT_MIN, rank = 0; i < n; ++i) {
            int idx = idxs[i];
            if (arr[idx] > pre) {
                ++rank;
            }
            ret[idx] = rank;

            pre = arr[idx];
        }

        return ret;
    }
};
