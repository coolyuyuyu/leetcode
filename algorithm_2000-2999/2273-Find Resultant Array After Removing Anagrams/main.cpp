class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        std::function<vector<int>(const string&)> f = [](const string& word) {
            vector<int> cnts(26, 0);
            for (char c : word) {
                ++cnts[c - 'a'];
            }
            return cnts;
        };

        vector<string> ret;

        vector<int> preCnts;
        for (int i = 0, n = words.size(); i < n; ++i) {
            vector<int> curCnts = f(words[i]);
            if (curCnts != preCnts) {
                ret.push_back(words[i]);
                preCnts = curCnts;
            }
        }

        return ret;
    }
};
