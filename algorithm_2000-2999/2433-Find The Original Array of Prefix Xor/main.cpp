class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();

        vector<int> ret(n);
        ret[0] = pref[0];
        for (int i = 1; i < n; ++i) {
            ret[i] = pref[i - 1] ^ pref[i];
        }

        return ret;
    }
};
