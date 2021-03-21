class Solution {
public:
    // https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k
    int subarraySum(vector<int>& nums, int k) {
        int numSubArrs = 0;

        unordered_map<int, int> m; // <sum, number of subArray (from 1st to some in middle) equal to sum>

        int sum = 0;
        for (int num : nums) {
            sum += num;
            if (sum == k) {
                ++numSubArrs;
            }

            auto itr = m.find(sum - k);
            if (itr != m.end()) {
                numSubArrs += itr->second;
            }

            ++m[sum];
        }

        return numSubArrs;
    }
};