class Solution {
public:
    bool checkCompleting(const string& word, vector<int> cnts, int len) {
        for (char c : word) {
            if (0 < cnts[c - 'a']) {
                --cnts[c - 'a'];
                if (--len == 0) {
                    break;
                }
            }
        }
        return len == 0;
    }

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> cnts(26, 0);
        for (char c : licensePlate) {
            if (isalpha(c)) {
                ++cnts[tolower(c) - 'a'];
            }
        }
        int len = std::accumulate(cnts.begin(), cnts.end(), 0);

        bool found = false;
        size_t index;
        for (size_t i = 0; i < words.size(); ++i) {
            if (checkCompleting(words[i], cnts, len)) {
                cout << words[i] << " is completeing" << endl;;
                if (found) {
                    if (words[i].size() < words[index].size()) {
                        index = i;
                    }
                }
                else {
                    found = true;
                    index = i;
                }
            }
        }

        return words[index];
    }
};
