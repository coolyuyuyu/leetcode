class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size();
        vector<int> tags(n, 0);
        for (int i = 0; i < n; ++i) {
            for (char c : words[i]) {
                tags[i] |= 1 << (c - 'a');
            }
        }
        std::sort(tags.begin(), tags.end());

        int ret = 0;
        for (int cnt = 0, i = 0; i <= n; ++i) {
            if (i == n || (0 < i && tags[i - 1] != tags[i])) {
                ret += ((cnt * (cnt - 1)) / 2);
                cnt = 1;
            }
            else {
                ++cnt;
            }
        }
        return ret;
    }
};
