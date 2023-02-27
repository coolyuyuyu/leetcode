class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();

        vector<int> ret(n);
        long long remaining = 0;
        for (int i = 0; i < n; ++i) {
            remaining *= 10;
            remaining += (word[i] - '0');
            remaining %= m;

            ret[i] = (remaining == 0 ? 1 : 0);
        }

        return ret;
    }
};
