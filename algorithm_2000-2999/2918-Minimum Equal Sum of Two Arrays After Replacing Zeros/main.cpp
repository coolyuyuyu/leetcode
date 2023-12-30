class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long sum1 = 0, cnt1 = 0;
        for (int num : nums1) {
            sum1 += num;
            cnt1 += (num == 0);
        }

        long sum2 = 0, cnt2 = 0;
        for (int num : nums2) {
            sum2 += num;
            cnt2 += (num == 0);
        }

        if (sum1 + cnt1 < sum2 + cnt2) {
            return cnt1 == 0 ? -1 : sum2 + cnt2;
        }
        else if (sum1 + cnt1 == sum2 + cnt2) {
            return sum2 + cnt2;
        }
        else {
            return cnt2 == 0 ? -1 : sum1 + cnt1;
        }
    }
};
