class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        int step = std::gcd(n, k);
        
        long long ret = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < k; ++i) {
            if (visited[i]) {
                continue;
            }

            vector<int> nums;
            for (int j = i; j < n && !visited[j]; j += step) {
                nums.push_back(arr[j]);
                visited[j] = true;
            }

            std::sort(nums.begin(), nums.end());
            int median = nums[nums.size() / 2];
            for (int num : nums) {
                ret += abs(num - median);
            }
        }

        return ret;
    }
};

// sum(arr[0], ..., arr[k-1]) == sum(arr[1], ..., arr[k])
// => arr[0] = arr[k]
// => arr[0] = arr[k] = arr[2k] = arr[3k]
