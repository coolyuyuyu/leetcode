class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> pairs(n); // <num, idx>
        for (int i = 0; i < n; ++i) {
            pairs[i] = {arr[i], i};
        }
        std::sort(pairs.begin(), pairs.end());

        vector<int> ret(n);
        for (int i = 0, rank = 1; i < n; ++i) {
            if (i > 0 && pairs[i - 1].first < pairs[i].first) {
                ++rank;
            }
            ret[pairs[i].second] = rank;
        }

        return ret;
    }
};
