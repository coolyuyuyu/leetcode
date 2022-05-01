class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        priority_queue<int> pq; // max heap;
        int lftSum = 0;
        for (int num : nums) {
            pq.push(num);
            lftSum += num;
        }

        vector<int> ans;
        for (int rhtSum = 0; !pq.empty() && lftSum >= rhtSum; pq.pop()) {
            ans.push_back(pq.top());
            rhtSum += pq.top();
            lftSum -= pq.top();
        }

        return ans;
    }
};
