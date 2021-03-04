class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for (int asteroid : asteroids) {
            assert(asteroid != 0);

            if (asteroid > 0) {
                stk.push_back(asteroid);
            }
            else {
                while (true) {
                    if (stk.empty() || stk.back() < 0) {
                        stk.push_back(asteroid);
                        break;
                    }

                    int diff = stk.back() + asteroid;
                    if (0 < diff) {
                        break;
                    }
                    else if (diff == 0) {
                        stk.pop_back();
                        break;
                    }
                    else {
                        stk.pop_back();
                    }
                }
            }
        }

        return stk;
    }
};