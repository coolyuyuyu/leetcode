class Solution {
public:
    bool complete(const vector<int>& counts, const string& word) {
        int totalCount = accumulate(counts.begin(), counts.end(), 0);

        vector<int> newCounts = counts;
        for (char c : word) {
            size_t index = c - 'a';
            if (newCounts[index] >= 1) {
                --newCounts[index];
                --totalCount;
            }

            if (totalCount == 0) {
                return true;
            }
        }

        return false;
    }

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> counts(26, 0);
        for (char c : licensePlate) {
            if ('A' <= c && c <= 'Z') {
                ++counts[c - 'A'];
            }
            else if ('a' <= c && c <= 'z') {
                ++counts[c - 'a'];
            }
        }

        size_t ansIndex;
        bool foundOne = false;
        for (size_t i = 0; i < words.size(); ++i) {
            const string& word = words[i];
            if (complete(counts, word)) {
                if (foundOne) {
                    if (words[i].size() < words[ansIndex].size()) {
                        ansIndex = i;
                    }
                }
                else {
                    foundOne = true;
                    ansIndex = i;
                }
            }
        }

        return words[ansIndex];
    }
};