class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int result = 0;

        size_t count = points.size();
        for (size_t i = 0; i < count; ++i) {
            unordered_map<int, int> distances;
            for (size_t j = 0; j < count; ++j) {
                if (j == i) {
                    continue;
                }
                
                int dx = points[i].first - points[j].first;
                int dy = points[i].second - points[j].second;
                int distance = dx * dx + dy * dy;
                pair<unordered_map<int, int>::iterator, bool> p = distances.emplace(distance, 1);
                if (!p.second) {
                    ++p.first->second;
                }
            }

            for (unordered_map<int, int>::const_iterator iter = distances.begin(); iter != distances.end(); ++iter) {
                result += (iter->second * (iter->second - 1));
            }
        }

        return result;
    }
};