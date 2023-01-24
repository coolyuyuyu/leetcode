class Solution {
public:
    // Time: O(n)
    bool makeStringsEqual(string s, string target) {
        if (s == target) {
            return true;
        }

        bool sContain1 = s.find('1') != string::npos;
        bool tContain1 = target.find('1') != string::npos;
        return (sContain1 && tContain1);
    }
};

/*
00 => 00
10 => 11
01 => 11
11 => 10, 01
*/
