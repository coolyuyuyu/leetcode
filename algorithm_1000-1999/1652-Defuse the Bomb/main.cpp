class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if (k == 0) {return vector<int>(n, 0); }

        int lft, rht;
        if (k >= 0) {
            lft = 1, rht = k;
        }
        else {
            lft = n + k, rht = n - 1;
        }
        int sum = std::accumulate(code.begin() + lft, code.begin() + rht + 1, 0);

        vector<int> ret(n, 0);
        for (int i = 0; i < n; ++i) {
            ret[i] = sum;
            sum -= code[(lft++) % n];
            sum += code[(++rht) % n];
        }

        return ret;
    }
};
