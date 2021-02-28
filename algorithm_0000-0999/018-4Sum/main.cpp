class Solution {
public:
    const string getLetters(char d) {
        switch (d) {
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8':
            return "tuv";
        case '9':
            return "wxyz";
        default:
            break;
        }

        return "";
    }

    void letterCombinationsHelper(const string& digits, string& result, vector<string>& results) {
        if (result.size() == digits.size()) {
            results.push_back(result);
        }
        else {
            string letters = getLetters(digits.at(result.size()));
            for (size_t j = 0; j < letters.size(); ++j) {
                result.push_back(letters.at(j));
                letterCombinationsHelper(digits, result, results);
                result.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        
        vector<string> results; {
            size_t s = 0;
            for (size_t i = 0; i < digits.size(); ++i) {
                s += getLetters(digits.at(i)).size();
            }
            results.reserve(s);
        }

        string result;
        letterCombinationsHelper(digits, result, results);

        return results;
    }
};