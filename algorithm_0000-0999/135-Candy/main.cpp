class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int cnts[n];

        cnts[0] = 1;
        for (int i = 1; i < n; ++i) { // compare left
            if (ratings[i - 1] < ratings[i]) {
                cnts[i] = cnts[i - 1] + 1;
            }
            else {
                cnts[i] = 1;
            }
        }

        for (int i = n - 1; 0 < i--;) { // compare right
            if (ratings[i] > ratings[i + 1]) {
                cnts[i] = std::max(cnts[i], cnts[i + 1] + 1);
            }
        }

        return std::accumulate(cnts, cnts + n, 0);
    }
};
