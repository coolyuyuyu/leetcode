class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> ss;
        for (char c : s) {
            ss.insert(c);
        }

        return ss.size();
    }
};
