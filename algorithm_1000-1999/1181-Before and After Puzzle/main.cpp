class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        int n = phrases.size();

        vector<pair<string, string>> pairs(n);
        for (int i = 0; i < n; ++i) {
            const string& phrase = phrases[i];
            size_t pos1 = phrase.find(' ');
            string str1 = phrase.substr(0, pos1);
            size_t pos2 = phrase.rfind(' ');
            string str2 = (pos2 == string::npos ? phrase : phrase.substr(pos2 + 1));
            pairs[i] = {str1, str2};
        }

        set<string> s;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) { continue; }
                if (pairs[i].second != pairs[j].first) { continue; }
                string str = phrases[i] + phrases[j].substr(pairs[j].first.size());
                s.insert(str);
            }
        }

        return vector<string>(s.begin(), s.end());
    }
};
