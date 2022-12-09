class Solution {
public:
    // hash + prefix sum
    int numOfSubarrays(vector<int>& arr) {
        int M = 1e9 + 7;

        int cntEvenSum = 1;
        int cntOddSum = 0;

        int ret = 0;
        for (int presum = 0, i = 0; i < arr.size(); ++i) {
            presum += arr[i];
            if (presum & 1) { // odd
                ret = (ret + cntEvenSum) % M;
                ++cntOddSum;
            }
            else {
                ret = (ret + cntOddSum) % M;
                ++cntEvenSum;
            }
        }

        return ret;
    }
};

/*
X X X X X X
    i     j

sum[i+1:j] = presum[j] - presum[i]: odd sum
1. presum[j]: odd sum => presum[j]: even sum
2. presum[j]: even sum => presum[j]: odd sum
*/
