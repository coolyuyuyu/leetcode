class Solution {
public:
    vector<string> findRepeatedDnaSequences_slow(string s) {
        unordered_map<string, int> counts;
        vector<string> result;
        for (size_t i = 0; i + 9 < s.size(); ++i) {
            string seq = s.substr(i, 10);
            if (counts[seq] == 1) {
                result.push_back(seq);
            }

            ++counts[seq];
        }

        return result;
    }

    inline int encode(char c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
    }

    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) {
            return {};
        }

        bitset<1 << 20> seen, repeated;
        vector<string> result;

        bitset<20> pattern;
        for (size_t i = 0; i < 9; ++i) {
            pattern <<= 2;
            pattern |= encode(s[i]);
        }

        for (size_t i = 9; i < s.size(); ++i) {
            pattern <<= 2;
            pattern |= encode(s[i]);

            unsigned long id = pattern.to_ulong();
            bool isSeen = seen.test(id);
            if (isSeen && !repeated.test(id)) {
                result.push_back(s.substr(i - 9, 10));
                repeated.set(id);
            }
            else if (!isSeen) {
                seen.set(id);
            }
        }

        return result;
    }
};