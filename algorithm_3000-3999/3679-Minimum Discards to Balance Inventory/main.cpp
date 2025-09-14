class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();

        int ret = 0;

        unordered_map<int, int> cnts;
        vector<bool> discards(n, false);
        for (int i = 0; i < n; ++i) {
            ++cnts[arrivals[i]];
            if (i - w >= 0 && discards[i - w] == false) {
                int j = i - w;
                --cnts[arrivals[j]];
            }

            if (cnts[arrivals[i]] > m) {
                --cnts[arrivals[i]];
                discards[i] = true;
                ++ret;
            }
        }

        return ret;
    }
};
