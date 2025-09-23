class Solution {
public:
    int compareVersion(string version1, string version2) {
        std::function<vector<int>(string)> str2ver = [](string s) {
            vector<int> ret;
            for (int i = 0, v = 0; i <= s.size(); ++i) {
                if (i == s.size() || s[i] == '.') {
                    ret.push_back(v);
                    v = 0;
                }
                else {
                    v = v * 10 + (s[i] - '0');
                }
            }
            while (!ret.empty() && ret.back() == 0) {
                ret.pop_back();
            }

            return ret;
        };

        vector<int> v1 = str2ver(version1), v2 = str2ver(version2);
        for (int i = 0, n = std::max(v1.size(), v2.size()); i < n; ++i) {
            if (i < v1.size() && i < v2.size()) {
                if (v1[i] < v2[i]) {
                    return -1;
                }
                else if (v1[i] > v2[i]) {
                    return 1;
                }
            }
            else if (i < v1.size()) {
                return 1;
            }
            else {
                return -1;
            }
        }

        return 0;
    }
};
