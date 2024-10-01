class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int cnts[k];
        std::fill(cnts, cnts + k, 0);
        for (int num : arr) {
            ++cnts[(num % k + k) % k];
        }

        if (cnts[0] & 1) {
            return false;
        }
        for (int lft = 1, rht = k - 1; lft < rht; ++lft, --rht) {
            if ((cnts[lft] != cnts[rht]) & 1) {
                return false;
            }
        }
        if (k % 2 == 0 && cnts[k / 2] & 1) {
            return false;
        }

        return true;
    }
};
