class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int sums[k];
        std::fill(sums, sums + k, 0);

        int ret = INT_MIN;
        for (int i = energy.size(); 0 < i--;) {
            sums[i % k] += energy[i];
            ret = std::max(ret, sums[i % k]);
        }

        return ret;
    }
};
