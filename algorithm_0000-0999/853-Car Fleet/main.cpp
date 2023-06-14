class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<int> index(n);
        std::iota(index.begin(), index.end(), 0);
        std::sort(index.begin(), index.end(), [&](int i1, int i2) { return position[i1] < position[i2]; });

        int ret = 0;
        double elapsedTime = 0.0;
        for (int i = n; 0 < i--;) {
            double t = (target - position[index[i]]) * 1.0 / speed[index[i]];
            if (elapsedTime < t) {
                ++ret;
                elapsedTime = t;
            }
        }

        return ret;
    }
};
