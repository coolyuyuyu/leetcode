class Solution {
public:
    bool isVowel(char c) {
        switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
        }
    };

    int findTheLongestSubstring(string s) {
        int n = s.size();

        // state: binary representation of the parity of number of occurence of character
        // state2idx[state]: the least index of state of prefix
        unordered_map<int, int> state2idx;
        state2idx[0] = -1;

        int ret = 0;
        for (int i = 0, state = 0; i < n; ++i) {
            if (isVowel(s[i])) {
                state ^= (1 << (s[i] - 'a'));
            }

            // All vowel characters of substring appear even number of times
            if (state2idx.find(state) != state2idx.end()) {
                ret = std::max(ret, i - state2idx[state]);
            }
            else {
                state2idx.emplace(state, i);
            }
        }

        return ret;
    }
};
