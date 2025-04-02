class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> rhts(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            rhts[s[i] - 'a'] = i;
        }

        vector<int> ret;
        for (int i = 0, n = s.size(); i < n;) {
            int rhtMost = rhts[s[i] - 'a'];
            for (int j = i; j < rhtMost; ++j) {
                rhtMost = std::max(rhtMost, rhts[s[j] - 'a']);
            }

            ret.push_back(rhtMost - i + 1);

            i = rhtMost + 1;
        }

        return ret;
    }
};
