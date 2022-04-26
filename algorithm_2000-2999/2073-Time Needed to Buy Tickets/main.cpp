class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int totalTime = 0;
        for (size_t i = 0; i < tickets.size(); ++i) {
            totalTime += std::min(tickets[i],  tickets[k] - (k < i ? 1 : 0));
        }

        return totalTime;
    }
};
