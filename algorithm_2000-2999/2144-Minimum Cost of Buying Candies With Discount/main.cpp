class Solution {
public:
    int minimumCost(vector<int>& cost) {
        std::sort(cost.begin(), cost.end());

        int totalCost = 0;
        for (int n = cost.size(), i = 0; i < n; ++i) {
            if (i % 3 != n % 3)  {
                totalCost += cost[i];
            }
        }
        return totalCost;
    }
};
