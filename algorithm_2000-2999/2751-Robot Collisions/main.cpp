class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        int indexes[n];
        std::iota(indexes, indexes + n, 0);
        std::sort(indexes, indexes + n, [&](int idx1, int idx2){ return positions[idx1] < positions[idx2]; });

        stack<int> stk;
        for (int idx : indexes) {
            while (!stk.empty() && directions[stk.top()] == 'R' && directions[idx] == 'L' && healths[idx] > 0) {
                if (healths[stk.top()] < healths[idx]) {
                    healths[stk.top()] = 0;
                    healths[idx] -= 1;
                    stk.pop();
                }
                else if (healths[stk.top()] == healths[idx]) {
                    healths[stk.top()] = 0;
                    healths[idx] = 0;
                    stk.pop();
                }
                else {
                    if (--healths[stk.top()] == 0) {
                        stk.pop();
                    }
                    healths[idx] = 0;
                }
            }

            if (healths[idx] > 0) {
                stk.push(idx);
            }
        }

        vector<int> ret;
        for (int health : healths) {
            if (health) {
                ret.push_back(health);
            }
        }

        return ret;
    }
};
