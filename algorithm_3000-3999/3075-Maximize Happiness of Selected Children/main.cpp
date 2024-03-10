class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> maxPQ;
        for (int happy : happiness) {
            maxPQ.push(happy);
        }

        long long ret = 0;
        for (int i = 0; i < k; ++i) {
            ret += std::max(maxPQ.top() - i, 0);
            maxPQ.pop();
        }

        return ret;
    }
};
