class Solution {
public:
    vector<int> diStringMatch(string S) {
        int lo = 0;
        int hi = S.size();
        vector<int> ans(S.size() + 1);
        for (size_t i  = 0; i < S.size(); ++i) {
            if (S[i] == 'I') {
                ans[i] = lo++;
            }
            else {
                ans[i] = hi--;
            }
        }
        ans[S.size()] = lo;

        return ans;
    }
};