class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans(s.size() + 1);
        int lo = 0, hi = s.size();
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == 'I') {
                ans[i] = lo++;
            }
            else {
                ans[i] = hi--;
            }
        }
        ans.back() = lo++;

        return ans;
    }
};
