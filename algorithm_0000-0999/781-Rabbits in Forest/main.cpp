class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        for (int ans : answers) {
            ++m[ans];
        }

        int ret = 0;
        for (const auto& [a, b] : m) {
            int k = (b - 1) / (a + 1) + 1;
            ret += k * (a + 1);
        }

        return ret;
    }
};

