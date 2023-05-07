class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        std::function<int(int)> f = [&cost, &ans, &f](int root) {
            if (cost.size() <= (root * 2 + 1)) {
                return cost[root];
            }

            int lftSum = f(root * 2 + 1);
            int rhtSum = f(root * 2 + 2);
            ans += abs(lftSum - rhtSum);
            
            return cost[root] + std::max(lftSum, rhtSum);
        };
        f(0);

        return ans;
    }
};
