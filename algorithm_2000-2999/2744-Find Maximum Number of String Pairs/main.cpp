class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ret = 0;

        unordered_map<string, int> cnts;
        for (const string& word : words) {
            string rev = word;
            std::reverse(rev.begin(), rev.end());

            if (0 < cnts[rev]) {
                ++ret;
                --cnts[rev];
            }
            ++cnts[word];
        }

        return ret;
    }
};
