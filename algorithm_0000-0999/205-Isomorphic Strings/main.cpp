class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<bool> used(256, false);
        vector<unsigned char> table(256, 0);
        string::const_iterator iterA, iterB;
        for (iterA = s.begin(), iterB = t.begin(); iterA != s.end() && iterB != t.end(); ++iterA, ++iterB) {
            if (table[*iterA] == 0) {
                table[*iterA] = *iterB + 1;
                if (used[*iterB]) {
                    return false;
                }
                used[*iterB] = true;
            }
            else {
                if (table[*iterA] != *iterB + 1) {
                    return false;
                }
            }
        }

        return (iterA == s.end() && iterB == t.end());
    }
};