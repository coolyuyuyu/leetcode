class Solution {
public:
    static unordered_map<char, int> rows;

    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        for (size_t i = 0; i < words.size(); ++i) {
            const string& word = words[i];
            if (word.empty()) {
                result.push_back(word);
                continue;
            }

            int row = rows[word.front()];
            bool sameRow = true;
            for (size_t j = 1; j < word.size(); ++j) {
                if (rows[word[j]] != row) {
                    sameRow = false;
                    break;
                }
            }
            if (sameRow) {
                result.push_back(word);
            }
        }

        return result;
    }
};

unordered_map<char, int> Solution::rows = {
    {'q', 0},
    {'w', 0},
    {'e', 0},
    {'r', 0},
    {'t', 0},
    {'y', 0},
    {'u', 0},
    {'i', 0},
    {'o', 0},
    {'p', 0},
    {'Q', 0},
    {'W', 0},
    {'E', 0},
    {'R', 0},
    {'T', 0},
    {'Y', 0},
    {'U', 0},
    {'I', 0},
    {'O', 0},
    {'P', 0},
    {'a', 1},
    {'s', 1},
    {'d', 1},
    {'f', 1},
    {'g', 1},
    {'h', 1},
    {'j', 1},
    {'k', 1},
    {'l', 1},
    {'A', 1},
    {'S', 1},
    {'D', 1},
    {'F', 1},
    {'G', 1},
    {'H', 1},
    {'J', 1},
    {'K', 1},
    {'L', 1},
    {'z', 2},
    {'x', 2},
    {'c', 2},
    {'v', 2},
    {'b', 2},
    {'n', 2},
    {'m', 2},
    {'Z', 2},
    {'X', 2},
    {'C', 2},
    {'V', 2},
    {'B', 2},
    {'N', 2},
    {'M', 2},
};