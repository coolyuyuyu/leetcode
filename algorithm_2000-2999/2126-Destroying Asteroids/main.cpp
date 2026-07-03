class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        std::sort(asteroids.begin(), asteroids.end());

        long long sum = mass;
        for (int asteroid : asteroids) {
            if (asteroid > sum) { return false; }
            sum += asteroid;
        }

        return true;
    }
};
