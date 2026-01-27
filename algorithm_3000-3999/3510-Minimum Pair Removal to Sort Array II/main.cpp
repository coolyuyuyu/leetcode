class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        vector<long long> vals(n);
        for (int i = 0; i < n; ++i) {
            vals[i] = nums[i];
        }

        int nxts[n], pres[n];
        for (int i = 0; i < n; ++i) {
            nxts[i] = i + 1;
            pres[i] = i - 1;
        }

        int invCnt = 0;
        set<pair<long long, int>> s;
        for (int i = 0; i + 1 < n; ++i) {
            if (vals[i] > vals[i + 1]) {
                ++invCnt;
            }
            s.emplace(vals[i] + vals[i + 1], i);
        }

        int ret = 0;
        for (; invCnt > 0; ++ret) {
            int i = s.begin()->second, j = nxts[i];
            int p = pres[i], q = nxts[j];
            // p i j q

            s.erase({vals[i] + vals[j], i});
            if (vals[i] > vals[j]) { --invCnt; }
            if (p >= 0) {
                s.erase({vals[p] + vals[i], p});
                if (vals[p] > vals[i]) { --invCnt; }
            }
            if (q < n) {
                s.erase({vals[j] + vals[q], j});
                if (vals[j] > vals[q]) { --invCnt; }
            }

            vals[i] += vals[j];

            // p i q
            nxts[i] = q;
            if (p >= 0) {
                if (vals[p] > vals[i]) {
                    ++invCnt;
                }
                s.emplace(vals[p] + vals[i], p);
            }
            if (q < n) {
                pres[q] = i;
                if (vals[i] > vals[q]) {
                    ++invCnt;
                }
                s.emplace(vals[i] + vals[q], i);
            }
        }

        return ret;
    }
};
