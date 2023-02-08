class Solution {
public:
    bool checkVowel(char c) {
        switch(c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        size_t n = words.size();
        vector<int> presum(n, 0);
        for (size_t i = 0; i < n; ++i) {
            if (checkVowel(words[i].front()) && checkVowel(words[i].back())) {
                presum[i] = 1;
            }
        }
        std::partial_sum(presum.begin(), presum.end(), presum.begin());

        vector<int> ret(queries.size());
        for (size_t i = 0; i < queries.size(); ++i) {
            ret[i] = presum[queries[i][1]];
            if (0 < queries[i][0]) {
                ret[i] -= presum[queries[i][0] - 1];
            }
        }

        return ret;
    }
};
