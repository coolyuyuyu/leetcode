class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        vector<int> cubes;
        for (int i = 1; i * i * i <= n; ++i) {
            cubes.push_back(i * i * i);
        }

        unordered_map<int, int> cnts;
        for (int i = 0; i < cubes.size(); ++i) {
            for (int j = i + 1; j < cubes.size() && cubes[i] + cubes[j] <= n; ++j) {
                ++cnts[cubes[i] + cubes[j]];
            }
        }

        vector<int> ret;
        for (const auto& [x, cnt] : cnts) {
            if (cnt >= 2) {
                ret.push_back(x);
            }
        }
        std::sort(ret.begin(), ret.end());

        return ret;
    }
};
