class Solution {
public:
    int getBitIdx(char c) {
        switch (c) {
        case 'a': return 0;
        case 'e': return 1;
        case 'i': return 2;
        case 'o': return 3;
        case 'u': return 4;
        default: return -1;
        }
    };

    int findTheLongestSubstring(string s) {
        int n = s.size();

        // state: binary representation of the parity of number of occurence of each vowel character
        // state2idx[state]: the least index of state of prefix
        unordered_map<int, int> state2idx;
        state2idx[0] = -1;

        int ret = 0;
        for (int i = 0, state = 0; i < n; ++i) {
            int bidx = getBitIdx(s[i]);
            if (bidx >= 0) {
                state ^= (1 << bidx);
            }

            // All characters of substring appear even number of times
            if (state2idx.find(state) != state2idx.end()) {
                ret = std::max(ret, i - state2idx[state]);
            }

            state2idx.emplace(state, i);
        }

        return ret;
    }
};
