class Solution {
public:
    vector<int> findAllOccurences(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();

        // lps[i]: the maximum value k such that needle[0:k-1] == needle[i-k+1:i]
        int lps[n];
        lps[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && needle[j] != needle[i]) {
                j = lps[j - 1];
            }
            lps[i] = j + (needle[j] == needle[i] ? 1 : 0);
        }

        vector<int> ret;
        for (int i = 0, j = 0; i < m; ++i) {
            while ((j > 0 && haystack[i] != needle[j]) || j == n) {
                j = lps[j - 1];
            }
            j = j + (haystack[i] == needle[j] ? 1 : 0);

            if (j == n) {
                ret.push_back(i - n + 1);
            }
        }

        return ret;
    }

    int shortestMatchingSubstring(string s, string p) {
        int sepIdx1 = p.find('*', 0);
        int sepIdx2 = p.find('*', sepIdx1 + 1);
        string pre = p.substr(0, sepIdx1);
        string mid = p.substr(sepIdx1 + 1, sepIdx2 - sepIdx1 - 1);
        string suf = p.substr(sepIdx2 + 1);

        if (pre.empty() && mid.empty() && suf.empty()) {
            return 0;
        }
        else if (mid.empty() && suf.empty()) {
            return s.find(pre) != string::npos ? pre.size() : -1;
        }
        else if (pre.empty() && suf.empty()) {
            return s.find(mid) != string::npos ? mid.size() : -1;
        }
        else if (pre.empty() && mid.empty()) {
            return s.find(suf) != string::npos ? suf.size() : -1;
        }
        else if (pre.empty() || mid.empty() || suf.empty()) {
            string p1, p2;
            if (pre.empty()) {
                p1 = mid, p2 = suf;
            }
            else if (mid.empty()) {
                p1 = pre, p2 = suf;
            }
            else {
                p1 = pre, p2 = mid;
            }
            vector<int> indexes1 = findAllOccurences(s, p1);
            vector<int> indexes2 = findAllOccurences(s, p2);

            int ret = INT_MAX;
            for (int i1 = 0, i2 = 0; i1 < indexes1.size(); ++i1) {
                while (i2 < indexes2.size() && !(indexes1[i1] + p1.size() <= indexes2[i2])) {
                    ++i2;
                }
                if (i2 < indexes2.size()) {
                    ret = std::min<int>(ret, indexes2[i2] + p2.size() - indexes1[i1]);
                }
            }
            return ret != INT_MAX ? ret : -1;
        }
        else {
            vector<int> indexes1 = findAllOccurences(s, pre);
            vector<int> indexes2 = findAllOccurences(s, mid);
            vector<int> indexes3 = findAllOccurences(s, suf);

            int ret = INT_MAX;
            for (int i1 = 0, i2 = 0, i3 = 0; i1 < indexes1.size(); ++i1) {
                while (i2 < indexes2.size() && !(indexes1[i1] + pre.size() <= indexes2[i2])) {
                    ++i2;
                }
                if (i2 < indexes2.size()) {
                    while (i3 < indexes3.size() && !(indexes2[i2] + mid.size() <= indexes3[i3])) {
                        ++i3;
                    }
                    if (i3 < indexes3.size()) {
                        ret = std::min<int>(ret, indexes3[i3] + suf.size() - indexes1[i1]);
                    }
                }
            }
            return ret != INT_MAX ? ret : -1;
        }
    }
};
