class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> uset(words.begin(), words.end());
        for (const string& word : words) {
            for (int i = 1; i < word.size(); ++i)
            uset.erase(word.substr(i));
        }

        int ret = 0;
        for (const string& s : uset) {
            ret += s.size();
            ret += 1;
        }

        return ret;
    }
};
