class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> flags(26, false);
        for (char c : allowed) {
            flags[c - 'a'] = true;
        }

        size_t cnt = words.size();
        for (const string& word : words) {
            for (char c : word) {
                if (!flags[c - 'a']) {
                    --cnt;
                    break;
                }
            }
        }

        return cnt;
    }
};
