class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        std::sort(satisfaction.begin(), satisfaction.end(), std::greater<int>());

        int ret = 0;
        for (int i = 0, presum = 0; i < satisfaction.size(); ++i) {
            presum += satisfaction[i];
            if (presum <= 0) {
                return ret;
            }
            ret += presum;
        }

        return ret;
    }
};
