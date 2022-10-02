class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> weights;
        for (const auto&item : items1) {
            weights[item[0]] += item[1];
        }
        for (const auto&item : items2) {
            weights[item[0]] += item[1];
        }

        vector<vector<int>> ret;
        for (const auto&p : weights) {
            ret.push_back({p.first, p.second});
        }

        return ret;
    }
};
