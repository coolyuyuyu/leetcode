class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ret = 0;
        if (cost1 + cost2 >= costBoth) {
            int needBoth = std::min(need1, need2);
            ret += 1LL* needBoth * costBoth;
            need1 -= needBoth;
            need2 -= needBoth;
        }
        ret += 1LL * need1 * std::min(cost1, costBoth);
        ret += 1LL * need2 * std::min(cost2, costBoth);

        return ret;
    }
};
