class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ret;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].find(x) != string::npos) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
