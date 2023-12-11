class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        bool visited[n];
        std::fill(visited, visited + n, false);

        queue<int> q;

        visited[0] = true;
        q.push(0);

        while (!q.empty()) {
            int room = q.front();
            q.pop();

            for (int key : rooms[room]) {
                if (visited[key]) { continue; }

                visited[key] = true;
                q.push(key);
            }
        }

        return std::find(visited, visited + n, false) == visited + n;
    }
};
