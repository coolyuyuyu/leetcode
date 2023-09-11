class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ret;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < groupSizes.size(); ++i) {
            int groupSize = groupSizes[i];
            m[groupSize].push_back(i);
            if (m[groupSize].size() == groupSize) {
                ret.push_back(m[groupSize]);
                m[groupSize].clear();
            }
        }

        return ret;
    }
};
