class Solution {
public:
    int maximizeWin(vector<int>& positions, int k) {
        int n = positions.size();

        if ((positions.back() - positions.front()) <= (2 * k)) {
            return n;
        }

        vector<int> pre(n);
        for (int maxCnt = 0, lft = 0, rht = 0; rht < n; ++rht) {
            while (lft <= rht && k < (positions[rht] - positions[lft])){
                ++lft;
            }
            maxCnt = std::max(maxCnt, rht - lft + 1);
            pre[rht] = maxCnt;
        }

        vector<int> suf(n);
        for (int maxCnt = 0, lft = n - 1, rht = n - 1; 0 <= lft; --lft) {
            while (lft <= rht && k < (positions[rht] - positions[lft])){
                --rht;
            }
            maxCnt = std::max(maxCnt, rht - lft + 1);
            suf[lft] = maxCnt;
        }

        int ret = 0;
        for (int k = 0; (k + 1) < n; ++k) {
            ret = std::max(ret, pre[k] + suf[k + 1]);
        }

        return ret;
    }
};

// pre[i]: max number of prizes of a valid segment in positions[0:i]
// suf[j]: max number of prizes of a valid segment in positions[j:n-1]
// max number of prizes in two segment:
//     => max(pre[k] + suf[k+1]) for k = 0, 1, 2, ..., n-2
