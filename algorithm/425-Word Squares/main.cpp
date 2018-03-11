class Solution {
public:
    void wordSquaresHelper(const vector<string>& words, size_t index, size_t end, vector<string>& result, vector<vector<string>>& results) {
        if (index >= end) {
            results.emplace_back(result);
        }
        else {
            for (size_t i = 0; i < words.size(); ++i) {
                bool ok = true;
                for (size_t j = 0; j < index; ++j) {
                    if (result[j][index] != words[i][j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    result.emplace_back(words[i]);
                    wordSquaresHelper(words, index + 1, end, result, results);
                    result.pop_back();
                }
            }
        }

    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.empty()) {
            return {};
        }

        vector<string> result;
        vector<vector<string>> results;
        wordSquaresHelper(words, 0, words.front().size(), result, results);
        return results;
    }
};