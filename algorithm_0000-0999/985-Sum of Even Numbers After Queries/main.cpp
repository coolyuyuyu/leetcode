class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for (int num : nums) {
            if ((num % 2) == 0) {
                sum += num;
            }
        }

        int n = queries.size();
        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            int val = queries[i][0], idx = queries[i][1];
            cout << val << " " << idx << endl;
            if ((nums[idx] % 2) == 0) {
                sum -= nums[idx];
            }
            nums[idx] += val;
            if ((nums[idx] % 2) == 0) {
                sum += nums[idx];
            }

            ret[i] = sum;
        }

        return ret;
    }
};
