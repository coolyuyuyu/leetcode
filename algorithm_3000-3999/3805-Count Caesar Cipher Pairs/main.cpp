class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long ret = 0;

        unordered_map<string, int> word2cnt;
        for (string word : words) {
            int diff = 'z' - word[0];
            for (char& c : word) {
                c = 'a' + (c - 'a' + diff) % 26;
            }

            ret += word2cnt[word];
            ++word2cnt[word];
        }

        return ret;
    }
};
