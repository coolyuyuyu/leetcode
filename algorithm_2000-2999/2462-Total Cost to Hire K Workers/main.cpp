class Solution {
public:
    long long totalCost(vector<int> costs, int k, int candidates) {
        priority_queue<int, vector<int>, std::greater<int>> lftPQ, rhtPQ;

        int lft = 0, rht = costs.size() - 1;
        for (int i = 0; i < candidates && lft <= rht; ++i) {
            lftPQ.emplace(costs[lft++]);
            if (lft <= rht) {
                rhtPQ.emplace(costs[rht--]);
            }
        }

        long long c = 0;
        for (int i = 0; i < k; ++i) {
            if (lftPQ.empty()) {
                c += rhtPQ.top();
                rhtPQ.pop();
            }
            else if (rhtPQ.empty()) {
                c += lftPQ.top();
                lftPQ.pop();
            }
            else if (lftPQ.top() <= rhtPQ.top()) {
                c += lftPQ.top();
                lftPQ.pop();
                if (lft <= rht) {
                    lftPQ.push(costs[lft++]);
                }
            }
            else {
                c += rhtPQ.top();
                rhtPQ.pop();
                if (lft <= rht) {
                    rhtPQ.push(costs[rht--]);
                }
            }
        }

        return c;
    }
};
