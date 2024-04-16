class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();

        vector<int> ret;
        for (int i = n, mx = 0; 0 < i--;) {
            if (heights[i] > mx) {
                ret.push_back(i);
                mx = heights[i];
            }
        }
        std::reverse(ret.begin(), ret.end());

        return ret;
    }
};
