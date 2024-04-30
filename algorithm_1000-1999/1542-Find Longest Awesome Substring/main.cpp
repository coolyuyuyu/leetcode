class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();

        // state: binary representation of the parity of number of occurence of each digit
        // state2idx[state]: the least index of state of prefix
        unordered_map<int, int> state2idx;
        state2idx[0] = -1;

        int ret = 0;
        for (int i = 0, state = 0; i < n; ++i) {
            state ^= (1 << (s[i] - '0'));

            // All characters of substring appear even number of times
            if (state2idx.find(state) != state2idx.end()) {
                ret = std::max(ret, i - state2idx[state]);
            }
            // One character of substring appears odd number of times
            for (char c = '0'; c <= '9'; ++c) {
                if (state2idx.find(state ^ (1 << (c - '0'))) != state2idx.end()) {
                ret = std::max(ret, i - state2idx[state ^ (1 << (c - '0'))]);
                }
            }

            state2idx.emplace(state, i);
        }

        return ret;
    }
};
