class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> cnts1(26, 0), cnts2(26, 0);
        for (char c : word1) {
            ++cnts1[c - 'a'];
        }
        for (char c : word2) {
            ++cnts2[c - 'a'];
        }
        int size1 = std::count_if(cnts1.begin(), cnts1.end(), [](int c) { return (0 < c); });
        int size2 = std::count_if(cnts2.begin(), cnts2.end(), [](int c) { return (0 < c); });
        if (std::abs(size1 - size2) > 2) {
            return false;
        }

        for (int i = 0; i < 26; ++i) {
            if (cnts1[i] == 0) { continue; }
            for (int j = 0; j < 26; ++j) {
                if (cnts2[j] == 0) { continue; }
                int s1 = size1, s2 = size2;
                if(--cnts1[i] == 0) { --s1; }
                if(++cnts1[j] == 1) { ++s1; }
                if(--cnts2[j] == 0) { --s2; }
                if(++cnts2[i] == 1) { ++s2; }

                if (s1 == s2) {
                    return true;
                }

                ++cnts1[i];
                --cnts1[j];
                ++cnts2[j];
                --cnts2[i];

            }
        }

        return false;
    }
};
