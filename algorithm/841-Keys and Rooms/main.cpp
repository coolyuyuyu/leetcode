class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        size_t n = rooms.size();

        queue<int> keys;
        keys.emplace(0);
        vector<bool> locked(n, false);
        while (!keys.empty()) {
            int door = keys.front();
            keys.pop();

            if (locked[door]) {
                continue;
            }

            locked[door] = true;
            --n;
            for (int key : rooms[door]) {
                keys.emplace(key);
            }
        }

        return n == 0;
    }
};