class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> indexes(n);
        std::iota(indexes.begin(), indexes.end(), 0);
        std::sort(indexes.begin(), indexes.end(), [&](int i1, int i2) { return positions[i1] < positions[i2]; });

        vector<int> stk;
        for (int index : indexes) {
            while (!stk.empty() && directions[stk.back()] == 'R' && 0 < healths[index] && directions[index] == 'L') {
                if (healths[stk.back()] == healths[index]) {
                    healths[stk.back()] = 0;
                    stk.pop_back();
                    healths[index] = 0;
                }
                else if (healths[stk.back()]  < healths[index]) {
                    healths[stk.back()] = 0;
                    stk.pop_back();
                    healths[index] -= 1;
                }
                else {
                    healths[stk.back()] -= 1;
                    if (healths[stk.back()] == 0) {
                        stk.pop_back();
                    }
                    healths[index] = 0;
                }
            }
            if (0 < healths[index]) {
                stk.emplace_back(index);
            }
        }

        vector<int> ret;
        for (int health : healths) {
            if (0 < health) {
                ret.push_back(health);
            }
        }

        return ret;
    }
};
