class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        vector<int> cnts1(26, 0), cnts2(26, 0);
        for (size_t i = 0; i < word1.size(); ++i) {
            ++cnts1[word1[i] - 'a'];
            ++cnts2[word2[i] - 'a'];
        }
        for (size_t i = 0; i < 26; ++i) {
            if (cnts1[i] == 0 ^ cnts2[i] == 0) {
                return false;
            }
        }

        priority_queue<int> pq1, pq2;
        for (size_t i = 0; i < 26; ++i) {
            if (cnts1[i] == 0) {
                continue;
            }
            pq1.push(cnts1[i]);
            pq2.push(cnts2[i]);
        }

        while (!pq1.empty()) {
            if (pq1.top() != pq2.top()) {
                return false;
            }
            pq1.pop();
            pq2.pop();
        }

        return true;
    }
};
