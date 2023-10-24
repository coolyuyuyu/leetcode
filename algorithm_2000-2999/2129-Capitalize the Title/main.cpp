class Solution {
public:
    string capitalizeTitle(string title) {
        string ret;

        istringstream iss(title);
        for (string word; iss >> word;) {
            transform(word.begin(), word.end(), word.begin(), [](char c) { return std::tolower(c); });
            if (word.size() > 2) {
                word[0] = std::toupper(word[0]);
            }
            ret += word;
            ret += " ";
        }
        if (!ret.empty()) {
            ret.pop_back();
        }

        return ret;
    }
};

