class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mxNum = *std::max_element(nums.begin(), nums.end());

        int freqs[mxNum + 1];
        std::fill(freqs, freqs + mxNum + 1, 0);
        for (int num : nums) {
            ++freqs[num];
        }

        long long mFreqs[mxNum + 1];
        std::fill(mFreqs, mFreqs + mxNum + 1, 0);
        for (int num = mxNum; num >= 1; --num) {
            for (int multiple = num; multiple <= mxNum; multiple += num) {
                mFreqs[num] += freqs[multiple];
            }
        }

        long long  gcdFreqs[mxNum + 1];
        std::fill(gcdFreqs, gcdFreqs + mxNum + 1, 0);
        for (int num = mxNum; num >= 1; --num) {
            gcdFreqs[num] = 1LL * mFreqs[num] * (mFreqs[num] - 1) / 2;
            for (int multiple = num + num; multiple <= mxNum; multiple += num) {
                gcdFreqs[num] -= gcdFreqs[multiple];
            }
        }

        long long presums[mxNum + 1];
        std::partial_sum(gcdFreqs, gcdFreqs + mxNum + 1, presums);

        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            res[i] = std::upper_bound(presums, presums + mxNum + 1, queries[i]) - presums;
        }

        return res;
    }
};
