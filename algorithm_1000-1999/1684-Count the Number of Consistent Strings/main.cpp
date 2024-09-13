class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bitset<26> existed;
        for (char c : allowed) {
            existed[c - 'a'] = true;
        }

        int ret = words.size();
        for (const string& word : words) {
            for (char c : word) {
                if (!existed[c - 'a']) {
                    --ret;
                    break;
                };
            }
        }

        return ret;
    }
};
