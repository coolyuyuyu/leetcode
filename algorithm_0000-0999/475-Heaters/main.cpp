class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int radius = 0;
        int heaterIndex = 0;
        for (auto house: houses) {
            while (heaterIndex + 1 < heaters.size() && abs(heaters[heaterIndex + 1] - house) <= abs(heaters[heaterIndex] - house)) {
                ++heaterIndex;
            }
            radius = max(radius, abs(heaters[heaterIndex] - house));
        }

        return radius;
    }
};