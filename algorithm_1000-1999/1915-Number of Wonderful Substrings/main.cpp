class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();

        // state: binary representation of the parity of number of occurence of each character
        // dp[state]: the number of prefix of state
        unordered_map<int, int> dp;
        dp[0] = 1;

        long long ret = 0;
        for (int i = 0, state = 0; i < n; ++i) {
            state ^= (1 << (word[i] - 'a'));

            // All characters of substring appear even number of times
            ret += dp[state];
            // One character of substring appears odd number of times
            for (char c = 'a'; c <= 'j'; ++c) {
                ret += dp[state ^ (1 << (c - 'a'))];
            }

            ++dp[state];
        }

        return ret;
    }
};
