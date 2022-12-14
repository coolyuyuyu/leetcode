class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long ret = 0;

        int totalSamePairCnt = 0;
        map<int, int> samePairCnts;
        for (int i = 0; i < n; ++i) {
            if (nums1[i] == nums2[i]) {
                ++totalSamePairCnt;
                ++samePairCnts[nums1[i]];
                ret += i;
            }
        }

        int majorityNum, majorityCnt = 0;
        for (auto& [num, cnt] : samePairCnts) {
            if (majorityCnt < cnt) {
                majorityCnt = cnt;
                majorityNum = num;
            }
        }

        if (majorityCnt * 2 <= totalSamePairCnt) {
            return ret;
        }

        int pendingCnt = majorityCnt * 2 - totalSamePairCnt;
        assert(1 <= pendingCnt);
        for (int i = 0; i < n; ++i) {
            if (nums1[i] != nums2[i] && nums1[i] != majorityNum && nums2[i] != majorityNum) {
                ret += i;
                if (0 == --pendingCnt) {
                    return ret;
                }
            }
        }


        return -1;
    }
};

/*
nums1: 2 2 4 1 3
nums2: 1 2 4 3 3
=> diff pairs: 0, 3
=> same pairs: 1, 2, 4

nums1: 1 2 2 2 4
nums2: 1 2 2 2 4
=> same pairs: 1, 2, 3
=> majorityNum:2, majorityCnt = 3
=> find if there are () diff pairs which does not contain majority
*/
