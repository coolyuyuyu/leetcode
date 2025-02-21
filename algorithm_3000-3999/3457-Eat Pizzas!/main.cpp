class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n = pizzas.size();

        std::sort(pizzas.rbegin(), pizzas.rend());

        int cntO = ((n / 4) + 1) / 2;
        int cntE = n / 4 - cntO;

        long long ret = 0;

        int i = 0;
        while (0 < cntO--) {
            ret += pizzas[i++];
        }
        while (0 < cntE--) {
            ret += pizzas[i + 1];
            i += 2;
        }

        return ret;
    }
};
