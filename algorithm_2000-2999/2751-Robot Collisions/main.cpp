class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> indexes(positions.size());
        std::iota(indexes.begin(), indexes.end(), 0);
        std::sort(indexes.begin(), indexes.end(), [&](int i1, int i2) { return positions[i1] < positions[i2]; });

        stack<int> stk;
        for (int index : indexes) {
            while (!stk.empty() && directions[stk.top()] == 'R' && directions[index] == 'L') {
                if (healths[stk.top()] < healths[index]) {
                    healths[stk.top()] = 0;
                    healths[index] -= 1;
                    stk.pop();
                }
                else if (healths[stk.top()] == healths[index]) {
                    healths[stk.top()] = 0;
                    healths[index] = 0;
                    stk.pop();
                    break;
                }
                else {
                    healths[stk.top()] -= 1;
                    if (healths[stk.top()] == 0) {
                        stk.pop();
                    }
                    healths[index] = 0;
                    break;
                }
            }

            if (0 < healths[index]) {
                stk.push(index);
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
