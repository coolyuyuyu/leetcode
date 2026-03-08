class Solution {
public:
    string mergeCharacters(string s, int k) {
        string ret;

        int index = 0;
        unordered_map<char, int> indexes;
        for (char c : s) {
            if (indexes.find(c) == indexes.end() || index - indexes[c] > k) {
                ret += c;
                indexes[c] = index++;
            }
            else {
            }
        }

        return ret;
    }
};
