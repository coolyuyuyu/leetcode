class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> ans(S.size());
        for (int prev = 0 - S.size(), i = 0; i < S.size(); ++i) {
            if (S[i] == C) {
                prev = i;
            }
            ans[i] = i - prev;
        }
        for (int prev = INT_MAX, i = S.size() - 1; 0 <= i; --i) {
            if (S[i] == C) {
                prev = i;
            }
            ans[i] = min(ans[i], prev - i);
        }

        return ans;
    }
};