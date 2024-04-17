class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ret = 0, cur = capacity;
        for (int i = 0; i < plants.size(); ++i) {
            if (cur >= plants[i]) {
                ret += 1;
                cur -= plants[i];
            }
            else {
                ret += (i + i + 1);
                cur = capacity - plants[i];
            }
        }

        return ret;
    }
};
