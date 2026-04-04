class Solution {
public:
    char kthCharacter(string s, long long k) {
        int n = s.size();
        vector<long long> cnts(n, 1);
        for (int i = 0, t = 1; i < n; ++i) {
            if (s[i] == ' ') {
                t = 1;
            }
            else {
                cnts[i] = t++;
            }
        }
        vector<long long> presums(n);
        std::partial_sum(cnts.begin(), cnts.end(), presums.begin());

        return s[std::upper_bound(presums.begin(), presums.end(), k) - presums.begin()];
    }
};
