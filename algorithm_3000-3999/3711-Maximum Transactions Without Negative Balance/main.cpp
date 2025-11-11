class Solution {
public:
    int maxTransactions(vector<int>& transactions) {
        int n = transactions.size();
        priority_queue<int, vector<int>, std::greater<>> minPQ;

        int ret = n;

        long long sum = 0;
        for (int transaction: transactions) {
            sum += transaction;
            if (transaction < 0) {
                minPQ.emplace(transaction);
            }
            for (; sum < 0; --ret) {
                int t = minPQ.top();
                minPQ.pop();

                sum -= t;
            }
        }

        return ret;
    }
};
