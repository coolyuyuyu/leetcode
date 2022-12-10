class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == x) {
            return n;
        }

        unordered_map<int, int> m; // presum -> smallest index
        m[0] = -1;

        int maxLen = 0;
        for (int presum = 0, i = 0; i < nums.size(); ++i) {
            presum += nums[i];

            auto itr = m.find(presum - sum + x);
            if (itr != m.end()) {
                maxLen = std::max(maxLen, i - itr->second);
            }

            m.emplace(presum, i);
        }

        return maxLen == 0 ? -1 : (n - maxLen);
    }
};

/*
X X X X |X X X| X X
      j      i

n: size of nums
sum[0,j] + sum[i+1,n-1] == x
sum[j+1,i] = sum[0,n-1] - sum[0,j] + sum[i+1,n]
           = sum[0,n-1] - x
=> presum[i] - presum[j] = sum[0,n-1] - x
=> find longest subarray sum equals sum[0,n-1] - x
=> ans = n - size of longest subarray
*/
