class Solution {
public:
    // Time: O(n^2 * nlogn)
    int bruteForce(vector<int>& nums, int k, int p) {
        int n = nums.size();

        set<vector<int>> subarrs;
        for (int i = 0; i < n; ++i) {
            vector<int> subarr;
            int divCnt = 0;
            for (int j = i; j < n; ++j) {
                divCnt += (nums[j] % p == 0 ? 1 : 0);
                if (divCnt > k) {
                    break;
                }
                subarr.push_back(nums[j]);
                subarrs.insert(subarr);
            }
        }

        return subarrs.size();
    }

    // Time: O(n^2)
    int rollingHash(vector<int>& nums, int k, int p) {
        int n = nums.size();

        typedef unsigned long long ULL;
        ULL base = 211;
        ULL power = 1;

        int ret = 0;
        for (int len = 1; len <= n; ++len, power *= base) {
            unordered_set<ULL> hashs;

            ULL hash = 0;
            int divCnt = 0;
            for (int i = 0; i < n; ++i) {
                if (len <= i) {
                    hash -= nums[i - len] * power;
                    if (nums[i - len] % p == 0) {
                        --divCnt;
                    }
                }
                hash = hash * base + nums[i];
                if (nums[i] % p == 0) {
                    ++divCnt;
                }

                if (len - 1 <= i && divCnt <= k) {
                    hashs.insert(hash);
                }
            }

            ret += hashs.size();
        }

        return ret;
    }

    int countDistinct(vector<int>& nums, int k, int p) {
        //return bruteForce(nums, k, p);
        return rollingHash(nums, k, p);
    }
};
