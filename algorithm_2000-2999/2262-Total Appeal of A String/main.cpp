class Solution {
public:
    long long appealSum(string s) {
        vector<int> lastIndexes(26, -1);

        long long ret = 0;
        for (int i = 0, n = s.size(); i < n; ++i) {
            ret += 1LL * (i - lastIndexes[s[i] - 'a']) * (n - i);
            lastIndexes[s[i] - 'a'] = i;
        }

        return ret;
    }
};
