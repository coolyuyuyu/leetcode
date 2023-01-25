class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        long long diff1 = 0, diff2 = 0;
        for (int i = 0; i < n; ++i) {
            long long diff = nums2[i] - nums1[i];
            if (k == 0) {
                if (diff != 0) {
                    return -1;
                }
            }
            else {
                if ((diff % k) != 0) {
                    return -1;
                }
            }

            if (0 < diff) {
                diff1 += diff;
            }
            else if (diff < 0) {
                diff2 +=diff;
            }
        }

        if ((diff1 + diff2) != 0) {
            return -1;
        }

        if (k == 0) {
            return 0;
        }
        else {
            return diff1 / k;
        }
    }
};
