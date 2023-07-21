class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ret;
        for (int asteroid : asteroids) {
            while (!ret.empty() && 0 < ret.back() && asteroid < 0) {
                int diff = abs(ret.back()) - abs(asteroid);
                if (diff == 0) {
                    ret.pop_back();
                    asteroid = 0;
                }
                else if (diff < 0) {
                    ret.pop_back();
                }
                else {
                    asteroid = 0;
                }
            }

            if (asteroid != 0) {
                ret.push_back(asteroid);
            }
        }

        return ret;
    }
};
