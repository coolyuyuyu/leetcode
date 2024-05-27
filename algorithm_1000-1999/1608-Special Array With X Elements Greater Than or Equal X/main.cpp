class Solution {
public:
    // Time: O(n^2)
    int bruteforce(vector<int>& nums) {
        int n = nums.size();

        std::function<bool(int)> checkSpecial = [&](int x) {
            int cnt = 0;
            for (int num : nums) {
                if (num >= x) {
                    ++cnt;
                }
            }

            return x == cnt;
        };

        for (int i = 1; i <= n; ++i) {
            if (checkSpecial(i)) {
                return i;
            }
        }

        return -1;
    }

    // Time: O(nlogn)
    int bsearch(vector<int>& nums) {
        std::function<int(int)> cntGE = [&](int x) {
            int ret = 0;
            for (int num : nums) {
                if (num >= x) {
                    ++ret;
                }
            }

            return ret;
        };

        int lo = 1, hi = nums.size();
        while (lo <hi) {
            int mid = hi - (hi - lo) / 2;
            int cnt = cntGE(mid);
            if (cnt >= mid) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return cntGE(lo) == lo ? lo : -1;
    }

    // Time: O(n)
    int countsort(vector<int>& nums) {
        int n = nums.size();
        int cnts[n + 1];
        std::fill(cnts, cnts + n + 1, 0);
        for (int num : nums) {
            ++cnts[std::min(num, n)];
        }

        for (int i = n, cnt = 0; i >= 0; --i) {
            cnt += cnts[i];
            if (cnt == i) {
                return cnt;
            }
        }

        return -1;
    }

    int specialArray(vector<int>& nums) {
        //return bruteforce(nums);
        //return bsearch(nums);
        return countsort(nums);
    }
};
