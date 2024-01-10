class Solution {
public:
    // Time: O(n^2)
    int f1(string word) {
        int n = word.size();

        vector<int> digits = {1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9};
        std::function<int(char)> mapChar = [&](char c) {
            return digits[c - 'a'];
        };

        int ret = 0;
        for (int len = 1; len <= n; ++len) {
            for (int i = 0, j = 0, sum = 0; i + len <= n; ++i) {
                for (; j - i < len; ++j) {
                    sum += mapChar(word[j]);
                }

                if (sum % len == 0) {
                    ++ret;
                }

                sum -= mapChar(word[i]);
            }
        }

        return ret;
    }

    // Time: O(n)
    int f2(string word) {
        // X X X [X X X X X]
        //     j          i

        // presum[i] - presum[j] = k * (i - j)
        // => presum[i] - k*i = presum[j] - k*j

        int n = word.size();
        word = "#" + word;

        vector<int> digits = {1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9};
        std::function<int(char)> mapChar = [&](char c) {
            return digits[c - 'a'];
        };

        unordered_map<int, int> m[10];
        for (int k = 1; k <= 9; ++k) {
            m[k][0 - 0 * k] = 1;
        }

        int ret = 0;
        for (int i = 1, presum = 0; i <= n; ++i) {
            presum += mapChar(word[i]);
            for (int k = 1; k <= 9; ++k) {
                int key = presum - k * i;
                ret += m[k][key];
                ++m[k][key];
            }
        }

        return ret;
    }

    int countDivisibleSubstrings(string word) {
        //return f1(word);
        return f2(word);
    }
};
