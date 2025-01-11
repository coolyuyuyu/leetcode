class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) {
            return false;
        }

        vector<int> cnts(26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }

        int cntOdds = std::count_if(cnts.begin(), cnts.end(), [](int cnt){ return cnt & 1; });
        if (cntOdds > k) {
            return false;
        }

        return true;
    }
};
