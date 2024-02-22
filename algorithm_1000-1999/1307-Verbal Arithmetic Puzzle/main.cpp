class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        int digits[26];
        std::fill(digits, digits + 26, -1);

        int m = words.size();
        int n = 0;
        for (string& word : words) {
            std::reverse(word.begin(), word.end());
            n = std::max<int>(n, word.size());
        }
        std::reverse(result.begin(), result.end());
        n = std::max<int>(n, result.size());

        int state = 0;
        std::function<bool(int, int, int)> dfs = [&](int i, int j, int sum) {
            if (j >= n) {
                return sum == 0;
            }
            else if (i >= m) {
                if (j >= result.size()) { return false; }
                char c = result[j];
                int d = digits[c - 'A'];
                if (d >= 0) {
                    if (d != sum % 10) { return false; }
                    if (j + 1 == result.size() && j > 0 && d == 0) { return false; }
                    return dfs(0, j + 1, sum / 10);
                }
                else {
                    d = sum % 10;
                    if (state & (1 << d)) { return false; }
                    if (j + 1 == result.size() && j > 0 && d == 0) { return false; }
                    digits[c - 'A'] = d;
                    state |= (1 << d);
                    if (dfs(0, j + 1, sum / 10)) {
                        return true;
                    }
                    state &= ~(1 << d);
                    digits[c - 'A'] = -1;
                    return false;
                }
            }
            else if (j >= words[i].size()) {
                return dfs(i + 1, j, sum);
            }

            const string& word = words[i];
            char c = word[j];
            int d = digits[c - 'A'];
            if (d >= 0) {
                if (j + 1 == word.size() && j > 0 && d == 0) { return false; }
                return dfs(i + 1, j, sum + digits[c - 'A']);
            }
            else {
                for (d = (j + 1 == word.size() && j > 0) ? 1 : 0; d < 10; ++d) {
                    if (state & (1 << d)) { continue; }
                    digits[c - 'A'] = d;
                    state |= (1 << d);
                    if (dfs(i + 1, j, sum + d)) {
                        return true;
                    }
                    state &= ~(1 << d);
                    digits[c - 'A'] = -1;
                }
                return false;
            }
        };

        return dfs(0, 0, 0);
    }
};
