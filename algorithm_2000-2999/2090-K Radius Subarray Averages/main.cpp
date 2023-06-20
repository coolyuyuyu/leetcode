class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ret(n);

        long sum = 0;
        for (int i = 0; i < k && i < n; ++i) {
            sum += nums[i];
        }
        for (int i = 0; i < n; ++i) {
            if ((i + k) < n) {
                sum += nums[i + k];
            }

            if (k <= i && (i + k) < n) {
                ret[i] = sum / (k * 2 + 1);
            }
            else {
                ret[i] = -1;
            }

            if (k <= i) {
                sum -= nums[i - k];
            }
        }

        return ret;
    }
};
