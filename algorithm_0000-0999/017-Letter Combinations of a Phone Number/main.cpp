class Solution {
public:
    static vector<string> s_lettersList;

    static const string& getLetters(char c) {
        return s_lettersList[c - '0'];
    }

    void letterCombinationsRecv(const string& digits, string& result, vector<string>& results) {
        if (result.size() == digits.size()) {
            results.push_back(result);
        }
        else {
            const string& letters = getLetters(digits[result.size()]);
            for (size_t i = 0; i < letters.size(); ++i) {
                result.push_back(letters[i]);
                letterCombinationsRecv(digits, result, results);
                result.pop_back();
            }
        }
    }

    vector<string> letterCombinationsRecv(const string& digits) {
        if (digits.empty()) {
            return {};
        }

        string result;

        vector<string> results; {
            size_t num = 1;
            for (size_t i = 0; i < digits.size(); ++i) {
                num *= getLetters(digits[i]).size();
            }
            results.reserve(num);
        }

        letterCombinationsRecv(digits, result, results);
        return results;
    }

    vector<string> letterCombinationsIter(const string& digits) {
        if (digits.empty()) {
            return{};
        }

        string result;
        vector<string> results;
        size_t num = 1;
        for (size_t i = 0; i < digits.size(); ++i) {
            const string& letters = getLetters(digits[i]);
            num *= letters.size();
            result.push_back(letters.front());
        }
        results.reserve(num);
        results.push_back(result);

        while (true) {
            size_t index = digits.size();
            for (; index > 0; --index) {
                const string& letters = getLetters(digits[index - 1]);
                if (result[index - 1] == letters.back()) {
                    result[index - 1] = letters.front();
                }
                else {
                    break;
                }
            }

            if (index == 0) {
                break;
            }

            const string& letters = getLetters(digits[index - 1]);
            result[index - 1] = letters[letters.find(result[index - 1]) + 1];
            results.push_back(result);
        }

        return results;
    }

    vector<string> letterCombinations(string digits) {
        return letterCombinationsRecv(digits);
    }
};

vector<string> Solution::s_lettersList = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};