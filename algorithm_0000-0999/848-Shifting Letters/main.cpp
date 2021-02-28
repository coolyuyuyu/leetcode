class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        assert(!shifts.empty());

        shifts.back() %= 26;
        auto lambda = [](int a, int b) {
            return (a  + (b % 26) % 26);
        };
        partial_sum(shifts.rbegin(), shifts.rend(), shifts.rbegin(), lambda);

        for (size_t i = 0; i < S.size(); ++i) {
            S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';
        }

        return S;
    }
};