class Solution {
public:
    int minimumCost(vector<int>& cost) {
        std::sort(cost.begin(), cost.end());

        int ret = 0;
        for (int i = 0, target = cost.size() % 3; i < cost.size(); ++i) {
            if (i % 3 == target) { continue; }
            ret += cost[i];
        }

        return ret;
    }
};
