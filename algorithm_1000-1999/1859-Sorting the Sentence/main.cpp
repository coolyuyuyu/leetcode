class Solution {
public:
    string sortSentence(string s) {
        vector<pair<string, char>> pairs;

        istringstream iss(s);
        for (string token; iss >> token;) {
            char idx = token.back();
            token.pop_back();

            pairs.emplace_back(token, idx);
            cout << token << endl;;
        }
        std::sort(pairs.begin(), pairs.end(), [](const auto& p1, const auto& p2) { return p1.second < p2.second; });

        string ret;
        for (const auto& [word, _] : pairs) {
            ret += word;
            ret += " ";
        }
        if (!ret.empty()) {
            ret.pop_back();
        }

        return ret;
    }
};
