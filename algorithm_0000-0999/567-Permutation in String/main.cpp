class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnts(26, 0);
        for (char c : s1) {
            ++cnts[c - 'a'];
        }
        int uniqueCnt = std::count_if(cnts.begin(), cnts.end(), [](int cnt) { return cnt > 0; });

        int k = s1.size();
        int n = s2.size();
        for (int i = 0; i < n; ++i) {
            if (--cnts[s2[i] - 'a'] == 0) {
                --uniqueCnt;
            }

            if (i + 1 - k >= 0) {
                if (uniqueCnt == 0) {
                    return true;
                }

                if (cnts[s2[i + 1 - k] - 'a']++ == 0) {
                    ++uniqueCnt;
                }
            }
        }

        return false;
    }
};
