class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ret = 0;

        for (int i = 0; i < k; ++i) {
            ret += std::min(tickets[i], tickets[k]);
        }
        ret += tickets[k];
        for (int i = k + 1; i < tickets.size(); ++i) {
            ret += std::min(tickets[i], tickets[k] - 1);
        }

        return ret;
    }
};
