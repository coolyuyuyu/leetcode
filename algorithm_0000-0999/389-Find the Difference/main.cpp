class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> counts(26, 0);
        for (auto c : s) {
            ++counts[c - 'a'];
        }
        
        for (auto c : t) {
            if (counts[c - 'a'] == 0) {
                return c;
            }
            --counts[c - 'a'];
        }
        
        return 0;
    }
};