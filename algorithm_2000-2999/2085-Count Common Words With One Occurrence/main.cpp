class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> cnts;
        for (const string& word : words1) {
            ++cnts[word];
        }
        for (const string& word : words2) {
            auto itr = cnts.find(word);
            if (itr != cnts.end() && itr->second < 2) {
                --(itr->second);
            }
        }

        return std::count_if (cnts.begin(), cnts.end(), [](const pair<string, int>& p) { return p.second == 0; });
    }
};
