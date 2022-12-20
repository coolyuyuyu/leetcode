class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        size_t n = rooms.size();
        vector<bool> visited(n, false);
        for (queue<int> keys({0}); !keys.empty();) {
            int door = keys.front();
            keys.pop();
            if (visited[door]) {
                continue;
            }

            visited[door] = true;
            --n;

            for (int key : rooms[door]) {
                keys.push(key);
            }
        }

        return n == 0;
    }
};
