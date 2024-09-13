class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> presum(arr.size());
        std::partial_sum(arr.begin(), arr.end(), presum.begin(), std::bit_xor<int>());

        vector<int> ret(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int lft = queries[i][0], rht = queries[i][1];
            ret[i] = presum[rht] ^ (lft > 0 ? presum[lft - 1] : 0);
        }

        return ret;
    }
};
