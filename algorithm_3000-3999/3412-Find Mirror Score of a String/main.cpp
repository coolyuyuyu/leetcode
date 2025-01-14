class Solution {
public:
    long long calculateScore(string s) {
        vector<stack<int>> stks(26);

        long long ret = 0;
        for (int i = 0, n = s.size(); i < n; ++i) {
            char mirror = 'z' - (s[i] - 'a');
            if (stks[mirror - 'a'].empty()) {
                stks[s[i] - 'a'].push(i);
                continue;
            }

            int j = stks[mirror - 'a'].top();
            stks[mirror - 'a'].pop();
            ret += i - j;
        }

        return ret;
    }
};
