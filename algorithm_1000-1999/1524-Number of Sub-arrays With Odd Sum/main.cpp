class Solution {
public:
    int M = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        // X X X X X X
        //     i     j

        // sum[i+1:j] = presum[j] - presum[i]: odd sum
        // 1. presum[j]: odd sum => presum[j]: even sum
        // 2. presum[j]: even sum => presum[j]: odd sum

        // cnts[0]: the number of prefix with even sums
        // cnts[i]: the number of prefix with odd sums
        int cnts[2] = {0, 0};
        cnts[0] = 1;

        int ret = 0;
        for (int i = 0, n = arr.size(), presum = 0; i < n; ++i) {
            presum += arr[i];
            ret = (ret + cnts[1 - presum & 1]) % M;
            ++cnts[presum & 1];
        }

        return ret;
    }
};
