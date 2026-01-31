class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ret;
        std::function<void(vector<int>&, int, int)> dfs = [&](vector<int>& comb, int n, int start) {
            if (n == 1) {
                if (comb.size() > 1) {
                    ret.push_back(comb);
                }
                return;
            }
            for (int i = start; i <= n; ++i) {
                if (n % i == 0) {
                    comb.push_back(i);
                    dfs(comb, n / i, i);
                    comb.pop_back();
                }
            }
        };
        vector<int> comb = {};
        dfs(comb, n, 2);

        return ret;
    }
};
