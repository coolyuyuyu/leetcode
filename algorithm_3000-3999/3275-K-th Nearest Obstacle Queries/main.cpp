class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n = queries.size();
        vector<int> ret(n);

        priority_queue<int> maxPQ;
        for (int i = 0; i < n; ++i) {
            int x = queries[i][0], y = queries[i][1];

            maxPQ.push(std::abs(x) + std::abs(y));
            if (maxPQ.size() > k) {
                maxPQ.pop();
            }

            ret[i] = (maxPQ.size() == k) ? maxPQ.top() : -1;
        }

        return ret;
    }
};
