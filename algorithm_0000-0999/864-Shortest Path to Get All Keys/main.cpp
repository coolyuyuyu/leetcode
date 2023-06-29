class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        int keyCnt = 0;
        
        vector<vector<unordered_set<int>>> visited(m, vector<unordered_set<int>>(n));
        queue<tuple<int, int, int>> q; // <r, c, state>
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '@') {
                    visited[r][c].insert(0);
                    q.emplace(r, c, 0);
                }
                else if (std::islower(grid[r][c])) {
                    ++keyCnt;
                }
            }
        }
        int finalState = (1 << keyCnt) - 1;

        for (int step = 0; !q.empty(); ++step) {
            for (int len = q.size(); 0 < len--;) {
                auto [r, c, s] = q.front();
                q.pop();

                if (s == finalState) {
                    return step;
                }
                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || m <= x || y < 0 || n <= y) { continue; } // out of range
                    if (grid[x][y] == '#') { continue; } // wall
                    if (isupper(grid[x][y]) && (s & (1 << (grid[x][y] - 'A'))) == 0) { continue; } // lock without key
                    
                    int state = s;
                    if (islower(grid[x][y])) { // pick key if necessary;
                        state |= (1 << (grid[x][y] - 'a'));
                    } 
                    if (visited[x][y].insert(state).second == false) { continue; } // visited

                    q.emplace(x, y, state);
                }
            }
        }

        return -1;
    }
};
