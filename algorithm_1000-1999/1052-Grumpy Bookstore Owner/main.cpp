class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int satisfied = 0;
        for (int i = 0; i < n; ++i) {
            if (!grumpy[i]) {
                satisfied += customers[i];
            }
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i]) {
                satisfied += customers[i];
            }

            ret = std::max(ret, satisfied);

            if (i + 1 >= minutes && grumpy[i + 1 - minutes]) {
                satisfied -= customers[i + 1 - minutes];
            }
        }

        return ret;
    }
};
