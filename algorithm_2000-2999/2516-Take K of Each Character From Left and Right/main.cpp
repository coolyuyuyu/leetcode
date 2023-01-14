class Solution {
public:
    int hash_presum(const string& s, int k) {
        vector<int> cntMaxs(3, 0);
        for (char c : s) {
            ++cntMaxs[c - 'a'];
        }
        if (std::any_of(cntMaxs.begin(), cntMaxs.end(), [&](int cnt) { return cnt < k; })) {
            return -1;
        }

        int n = s.size();
        int maxRetainLen = 0;
        vector<int> cnts(3, 0);
        vector<map<int, int>> indexes = {{{0, -1}}, {{0, -1}}, {{0, -1}}};
        for (int i = 0; i < n; ++i) {
            ++cnts[s[i] - 'a'];

            auto itrA = indexes[0].lower_bound(k - (cntMaxs[0] - cnts[0]));
            auto itrB = indexes[1].lower_bound(k - (cntMaxs[1] - cnts[1]));
            auto itrC = indexes[2].lower_bound(k - (cntMaxs[2] - cnts[2]));
            if (itrA != indexes[0].end() && itrB != indexes[1].end() && itrC != indexes[2].end()) {
                int i1 = i - itrA->second;
                int i2 = i - itrB->second;
                int i3 = i - itrC->second;

                maxRetainLen = std::max(maxRetainLen, std::min({i1, i2, i3}));
            }

            indexes[s[i] - 'a'][cnts[s[i] - 'a']] = i;
        }

        return n - maxRetainLen;
    }

    int slide_window(const string& s, int k) {
        vector<int> cnts(3, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }
        if (std::any_of(cnts.begin(), cnts.end(), [&](int cnt) { return cnt < k; })) {
            return -1;
        }

        int n = s.size();
        int maxRetainLen = 0;
        for (int lft = 0, rht = 0; lft < n; ++lft) { // [lft, rht)
            for (; std::all_of(cnts.begin(), cnts.end(), [&](int cnt) { return k <= cnt; }); ++rht) {
                maxRetainLen = std::max(maxRetainLen, rht - lft);
                if (rht == n) {
                    break;
                }
                
                --cnts[s[rht] - 'a'];
            }

            ++cnts[s[lft] - 'a'];
        }

        return n - maxRetainLen;
    }

    int takeCharacters(string s, int k) {
        //return hash_presum(s, k);
        return slide_window(s, k);
    }
};
