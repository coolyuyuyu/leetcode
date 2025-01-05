class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();

        int diffs[n + 1];
        std::fill(diffs, diffs + n + 1, 0);
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int diff = (direction == 1 ? 1 : -1);
            diffs[start] += diff;
            diffs[end + 1] -= diff;
        }

        for (int i = 0, sum = 0; i < n; ++i) {
            sum += diffs[i];
            s[i] = 'a' + ((s[i] - 'a' + sum) % 26 + 26) % 26;
        }

        return s;
    }
};
