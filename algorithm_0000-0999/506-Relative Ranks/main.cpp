class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        int indexes[n];
        std::iota(indexes, indexes + n, 0);
        std::sort(indexes, indexes + n, [&](int idx1, int idx2){ return score[idx1] > score[idx2]; });

        vector<string> ret(n);
        for (int i = 0; i < n; ++i) {
            switch(i) {
            case 0: ret[indexes[i]] = "Gold Medal"; break;
            case 1: ret[indexes[i]] = "Silver Medal"; break;
            case 2: ret[indexes[i]] = "Bronze Medal"; break;
            default: ret[indexes[i]] = std::to_string(i + 1); break;
            }
        }

        return ret;
    }
};
