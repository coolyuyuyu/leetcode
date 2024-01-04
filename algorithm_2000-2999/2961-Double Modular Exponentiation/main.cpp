class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        std::function<int(int, int, int)> f = [&](int base, int exp, int mod) {
            int ret = 1;
            for (; exp; exp >>= 1) {
                if (exp & 1) {
                    ret = (ret * base) % mod;
                }
                base = (base * base) % mod;
            }

            return ret;
        };

        vector<int> ret;
        for (int i = 0; i < variables.size(); ++i) {
            const auto& variable = variables[i];
            int a = variable[0], b = variable[1], c = variable[2], m = variable[3];
            if (f(f(a, b, 10), c, m) == target) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
