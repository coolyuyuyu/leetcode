class Solution {
public:
    // Time: O(n), Space(n)
    vector<int> f1(const vector<int>& nums, int n) {
        vector<int> ret(2 * n);
        for (int i = 0; i < n; ++i) {
            ret[2 * i] = nums[i];
            ret[2 * i + 1] = nums[i + n];
        }

        return ret;
    }

    // Time: O(n), Space(1)
    vector<int> f2(vector<int>& nums, int n) {
        for (int i = 0; i < n; ++i) {
            nums[i] += (nums[i + n] * 10000);
        }

        for (int i = n; 0 < i--;) {
            nums[2 * i + 1] = nums[i] / 10000;
            nums[2 * i] = nums[i] % 10000;
        }

        return nums;
    }

    vector<int> shuffle(vector<int>& nums, int n) {
        //return f1(nums, n);
        return f2(nums, n);
    }
};
