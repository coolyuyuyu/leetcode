class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<vector<int>, vector<string>> groups;
        for (const string& str : strings) {
            vector<int> distances;
            for (size_t i = 1; i < str.size(); ++i) {
                int distance = str[i] - str[i - 1];
                if (distance < 0) {
                    distance += 26;
                }
                distances.push_back(distance);
            }
            groups[distances].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto itr : groups) {
            ans.push_back(itr.second);
        }

        return ans;
    }
};