class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> maxPQ;
        for (int happy : happiness) {
            maxPQ.push(happy);
        }

        long long ret = 0;
        for (int i = 0; i < k; ++i) {
            int happy = maxPQ.top();
            maxPQ.pop();

            if (happy <= i) { return ret; }
            ret += happy - i;
        }

        return ret;
    }
};
