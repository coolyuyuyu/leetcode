class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> counts(26, 0);
        for (string::const_iterator iter = magazine.begin(); iter != magazine.end(); ++iter) {
            ++counts[*iter - 'a'];
        }

        for (string::const_iterator iter = ransomNote.begin(); iter != ransomNote.end(); ++iter) {
            if (counts[*iter - 'a'] == 0) {
                return false;
            }
            --counts[*iter - 'a'];
        }

        return true;
    }
};