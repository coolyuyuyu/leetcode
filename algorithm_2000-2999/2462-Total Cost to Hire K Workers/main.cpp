class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<>> lftPQ, rhtPQ;
        int lft = 0, rht = costs.size() - 1;
        for (int i = 0; i < candidates && lft <= rht; ++i) {
            lftPQ.push(costs[lft++]);
            if (lft <= rht) {
                rhtPQ.push(costs[rht--]);
            }
        }

        long long ret = 0;
        for (int i = 0; i < k; ++i) {
            if (rhtPQ.empty() || (!lftPQ.empty() && lftPQ.top() <= rhtPQ.top())) {
                ret += lftPQ.top();
                lftPQ.pop();
                if (lft <= rht) {
                    lftPQ.push(costs[lft++]);
                }
            }
            else {
                ret += rhtPQ.top();
                rhtPQ.pop();
                if (lft <= rht) {
                    rhtPQ.push(costs[rht--]);
                }
            }
        }

        return ret;
    }
};
