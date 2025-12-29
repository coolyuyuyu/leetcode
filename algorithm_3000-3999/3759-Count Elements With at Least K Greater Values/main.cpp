class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        priority_queue<int> maxPQ(nums.begin(), nums.end());

        int cnt = 0;
        while (cnt < k && !maxPQ.empty()) {
            ++cnt;
            int val = maxPQ.top();
            maxPQ.pop();

            while (!maxPQ.empty() && maxPQ.top() == val) {
                ++cnt;
                maxPQ.pop();
            }
        }

        return nums.size() - cnt;
    }
};
