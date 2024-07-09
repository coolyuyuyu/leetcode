class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int finish = 0;
        long sum = 0;
        for (const auto& customer : customers) {
            int arrival = customer[0], time = customer[1];

            finish = std::max(arrival, finish) + time;
            sum += finish - arrival;
        }

        return sum * 1.0 / customers.size();
    }
};
