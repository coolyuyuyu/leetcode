class Solution {
public:
    int minimumCost(vector<int>& nums) {
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for (int i = 1; i < nums.size(); ++i) {
            pq.push(nums[i]);
        }

        int x = nums[0];
        int y = pq.top(); pq.pop();
        int z = pq.top(); pq.pop();
        return x + y + z;
    }
};
