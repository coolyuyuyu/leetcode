class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        std::function<vector<int>(const string&)> getCnts = [](const string& word) {
            vector<int> cnts(26, 0);
            for (char c : word) {
                ++cnts[c - 'a'];
            }

            return cnts;
        };

        vector<int> cnts2(26, 0);
        for (const string& word2 : words2) {
            vector<int> cntsTmp = getCnts(word2);
            for (int i = 0; i < 26; ++i) {
                cnts2[i] = std::max(cnts2[i], cntsTmp[i]);
            }
        }

        vector<string> ret;
        for (const string& word1 : words1) {
            vector<int> cnts1 = getCnts(word1);
            bool universal = true;
            for (int i = 0; i < 26 && universal; ++i) {
                if (cnts1[i] < cnts2[i]) {
                    universal = false;
                }
            }

            if (universal) {
                ret.push_back(word1);
            }
        }

        return ret;
    }
};
