class Solution {
public:
    // Time: O(n)
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> maxStk, minStk;

        long long ret = 0;
        for (int i = 0; i <= n; ++i) {
            while (!maxStk.empty() && nums[maxStk.top()] > (i < n ? nums[i] : INT_MIN)) {
                int rht = i;
                int mid = maxStk.top(); maxStk.pop();
                int lft = maxStk.empty() ? -1 : maxStk.top();
                ret -= 1LL * nums[mid] * (mid - lft) * (rht - mid);
            }
            maxStk.push(i);

            while (!minStk.empty() && nums[minStk.top()] < (i < n ? nums[i] : INT_MAX)) {
                int rht = i;
                int mid = minStk.top(); minStk.pop();
                int lft = minStk.empty() ? -1 : minStk.top();
                ret += 1LL * nums[mid] * (mid - lft) * (rht - mid);
            }
            minStk.push(i);
        }

        return ret;
    }
};
