class Solution {
public:
    void letterCasePermutation(string& result, size_t index, vector<string>& results) {
        if (result.size() <= index) {
            results.emplace_back(result);
        }
        else {
            letterCasePermutation(result, index + 1, results);
            char c = result[index];
            if (isalpha(c)) {
                if (islower(c)) {
                    result[index] = toupper(c);

                }
                else {
                    result[index] = tolower(c);
                }
                letterCasePermutation(result, index + 1, results);
                result[index] = c;
            }
        }
    }

    vector<string> letterCasePermutation(string S) {
        string result = S;
        vector<string> results;
        letterCasePermutation(result, 0, results);
        return results;
    }
};