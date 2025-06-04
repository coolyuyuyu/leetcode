class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> openBoxes;
        unordered_set<int> lockBoxes;
        for (int box : initialBoxes) {
            if (status[box] == 1) {
                openBoxes.push(box);
            }
            else {
                lockBoxes.insert(box);
            }
        }

        int ret = 0;
        while (!openBoxes.empty()) {
            int cur = openBoxes.front();
            openBoxes.pop();

            ret += candies[cur];

            for (int nxt : containedBoxes[cur]) {
                if (status[nxt] == 1) {
                    openBoxes.push(nxt);
                }
                else {
                    lockBoxes.insert(nxt);
                }
            }
            for (int key : keys[cur]) {
                status[key] = 1;
                if (lockBoxes.find(key) != lockBoxes.end()) {
                    openBoxes.push(key);
                    lockBoxes.erase(key);
                }
            }
        }

        return ret;
    }
};
