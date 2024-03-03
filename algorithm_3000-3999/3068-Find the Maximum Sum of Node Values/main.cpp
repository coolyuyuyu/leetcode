class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        priority_queue<long long> diffs;
        for (int num : nums) {
            diffs.push((num ^ k) - num);
        }

        long long ret = 0;
        while (diffs.size() >= 2) {
            long long diff1 = diffs.top(); diffs.pop();
            long long diff2 = diffs.top(); diffs.pop();
            if (diff1 + diff2 > 0) {
                ret += diff1 + diff2;
            }
            else {
                break;
            }
        }

        return ret + std::accumulate(nums.begin(), nums.end(), 0LL);
    }
};
