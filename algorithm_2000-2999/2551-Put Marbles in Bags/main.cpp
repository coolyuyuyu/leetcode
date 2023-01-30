class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> vals(weights.size() - 1);
        for (int i = 0; i < vals.size(); ++i) {
            vals[i] = weights[i] + weights[i + 1];
        }
        std::sort(vals.begin(), vals.end());

        long long ret = 0;
        for (int i = 0; (i + 1) < k; ++i) {
            ret -= vals[i];
            ret += vals[vals.size() - i - 1];
        }

        return ret;

    }
};
