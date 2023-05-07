class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();

        vector<int> ret(n);
        vector<int> lis;
        for (int i = 0; i < n; ++i) {
            auto itr = std::upper_bound(lis.begin(), lis.end(), obstacles[i]);
            ret[i] = std::distance(lis.begin(), itr) + 1;
            if (itr == lis.end()) {
                lis.push_back(obstacles[i]);
            }
            else {
                *itr = obstacles[i];
            }
        } 

        return ret;
    }
};
