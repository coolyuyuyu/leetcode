class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        for (size_t i = shifts.size(); 0 < i--;) {
            if (i + 1 == shifts.size()) {
                shifts[i] %= 26;
            }
            else {
                shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
            }
        }

        for (size_t i = 0; i < S.size(); ++i) {
            S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';
        }

        return S;
    }
};