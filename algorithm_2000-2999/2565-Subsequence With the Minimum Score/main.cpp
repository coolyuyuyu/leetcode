class Solution {
public:
    int minimumScore(string s, string t) {
        int m = s.size(), n = t.size();

        // dpL[i]: k such that the shorstest prefix of s such that t[0:i] is subsequence of s[0:k]
        vector<int> dpL(n, INT_MAX);
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < m && s[j] != t[i]) {
                ++j;
            }
            if (j < m && s[j] == t[i]) {
                dpL[i] = j++;
            }
        }
        if (dpL.back() != INT_MAX) {
            return 0;
        }

        // dpR[i]: k such that the shorstest suffix of s such that t[i:n-1] is subsequence of s[k:m-1]
        vector<int> dpR(n, INT_MIN);
        for (int i = n - 1, j = m - 1; 0 <= i; --i) {
            while (0 <= j && s[j] != t[i]) {
                --j;
            }
            if (0 <= j && s[j] == t[i]) {
                dpR[i] = j--;
            }
        }
        if (dpR.front() != INT_MIN) {
            return 0;
        }

        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (isOk(dpL, dpR, mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    bool isOk(const vector<int>& dpL, const vector<int>& dpR, int windowLen) {
        int n = dpL.size();
        assert(n != windowLen);

        if (dpL[n - windowLen - 1] != INT_MAX || dpR[windowLen] != INT_MIN) {
            return true;
        }

        for (int i = 1; (i + windowLen) < n; ++i) {
            if (dpL[i - 1] < dpR[i + windowLen]) {
                return true;
            }
        }
        return false;
    }
};

// Break t into 3 part
// t: [a a a] [b b b] [c c c]
//    [a a a]                   is prefix of s
//                    [c c c]   is suffix of s
//            [b b b]           is the removed part of s, let this part shortest
// 
// 
// for [a a a]
//     => dpL[i]: k such that the shorstest prefix of s such that t[0:i] is subsequence of s[0:k]
// for [c c c]
//     => dpR[i]: k such that the shorstest suffix of s such that t[i:n-1] is subsequence of s[k:m-1]
// 
// binary search find shortest length of [b b b] such that
//     [..... i] [b b b] [j .....] and dpL[i] < dpR[j]
