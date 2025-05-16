class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ret = 0;

        unordered_map<int, int> cnts;
        for (const auto& dominoe : dominoes) {
            int a = dominoe[0], b = dominoe[1];
            if (b < a) { std::swap(a, b); }

            ret += cnts[a * 10 + b]++;
        }

        return ret;
    }
};
