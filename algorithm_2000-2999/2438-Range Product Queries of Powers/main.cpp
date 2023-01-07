class Solution {
public:
    int M = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> exps;
        for (int i = 0; n; ++i, n /= 2) {
            if (n % 2) {
                exps.push_back(i);
            }
        }
        vector<int> presum(exps.size());
        std::partial_sum(exps.begin(), exps.end(), presum.begin());

        vector<int> powers(32 * 32);
        powers[0] = 1;
        for (size_t i = 1; i < powers.size(); ++i) {
            powers[i] = (powers[i - 1] * 2) % M;
        }


        vector<int> answers(queries.size(), 1);
        for (size_t i = 0; i < queries.size(); ++i) {
            int exp = presum[queries[i][1]];
            if (0 < queries[i][0]) {
                exp -= presum[queries[i][0] - 1];
            }

            answers[i] = powers[exp];
        }

        return answers;
    }
};

// 11 =   1 +   2 +   8
//    = 2^0 + 2^1 + 2^3

// maximal n: 0111111....1
// product of all powers of 2: 0 + 1 + 2 + ... + 30 = (0 + 30) * (31) / 2
