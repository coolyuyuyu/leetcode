class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        long long reg = 0, exp = LLONG_MAX / 2;
        int m = regular.size();

        vector<long long> ret(m);
        for (int i = 0; i < m; ++i) {
            long long regTmp = reg, expTmp = exp;
            reg = std::min(regTmp + regular[i], expTmp + regular[i]);
            exp = std::min(regTmp + expressCost + express[i], expTmp + express[i]);

            ret[i] = std::min(reg, exp);
        }

        return ret;
    }
};
