class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0, f = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            f += i * nums[i];
        }

        int ret = f;
        for (int i = 1; i < n; ++i) {
            f = f + sum - n * nums[n - i];
            ret = std::max(ret, f);
        }

        return ret;
    }
};

// F[0] = 0*A[0] + 1*A[1] + 2*A[2]... + (n-2)*A[n-2] + (n-1)*A[n-1]
// F[1] = 0*A[n-1] + 1*A[0] + 2*A[1] + ... + (n-1)*A[n-2]
//      = F[0] + sum - n * A[n-1]
// ...
