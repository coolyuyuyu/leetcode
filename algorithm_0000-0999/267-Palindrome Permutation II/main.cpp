class Solution {
public:
    bool canPermutePalindrome(const string& s) {
        unordered_set<char> chars;
        for (char c : s) {
            if (chars.find(c) != chars.end()) {
                chars.erase(c);
            }
            else {
                chars.insert(c);
            }
        }

        if (2 <= chars.size()) {
            return false;
        }
        else if (chars.size() == 1) {
            return s.size() % 2 == 1;
        }
        else {
            return true;
        }
    }

    void generatePalindromes(size_t level, size_t threshold, vector<size_t>& counts, string& result, vector<string>& results) {
        if (threshold <= level) {
            results.push_back(result);
        }

        size_t need = 1 + (result.size() % 2 && level == result.size() / 2 ? 0 : 1);
        for (size_t i = 0; i < 128; ++i) {
            if (counts[i] >= need) {
                result[level] = (char)i;
                result[result.size() - level - 1] = (char)i;

                counts[i] -= need;
                generatePalindromes(level + 1, threshold, counts, result, results);
                counts[i] += need;
            }
        }
    }

    vector<string> generatePalindromes(string s) {
        if (!canPermutePalindrome(s)) {
            return {};
        }

        size_t threshold = s.size() / 2 + (s.size() % 2 ? 1 : 0);

        vector<size_t> counts(128, 0);
        for (char c : s) {
            ++counts[c];
        }

        string result = s;
        vector<string> results;
        generatePalindromes(0, threshold, counts, result, results);

        return results;
    }
};