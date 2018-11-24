class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        for (size_t i = 0; i < s.size(); ++i) {
            if (i + 1 <= s.size() && s[i] == '+' && s[i + 1] == '+') {
                ans.push_back(s);
                ans.back()[i] = '-';
                ans.back()[i + 1] = '-';
            }
        }

        return ans;
    }
};