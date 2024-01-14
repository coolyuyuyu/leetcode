class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        int n = word1.size();

        vector<int> cnts1(26, 0), cnts2(26, 0);
        for (int i = 0; i < n; ++i) {
            ++cnts1[word1[i] - 'a'];
            ++cnts2[word2[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if ((cnts1[i] == 0) ^ (cnts2[i] == 0)) {
                return false;
            }
        }

        priority_queue<int> pq1(cnts1.begin(), cnts1.end()), pq2(cnts2.begin(), cnts2.end());
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
