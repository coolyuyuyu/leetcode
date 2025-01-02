class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.size();

        int k = 0;
        for (const auto& s : shift) {
            k += (s[0] == 0 ? 1 : -1) * s[1];
        }
        k = (k % n + n) % n;
        std::rotate(s.begin(), s.begin() + k, s.end());

        return s;
    }
};
