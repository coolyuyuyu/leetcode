class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        string ret = s;
        for (int k = 1; k <= n; ++k) {
            string lft = s.substr(0, k), rht = s.substr(k);
            string revLft(lft.rbegin(), lft.rend()), revRht(rht.rbegin(), rht.rend());
            ret = std::min({ret, revLft + rht, lft + revRht});
        }

        return ret;
    }
};
