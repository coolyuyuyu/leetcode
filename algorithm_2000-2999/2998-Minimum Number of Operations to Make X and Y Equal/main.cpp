class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        unordered_set<int> visited({x});

        queue<int> q({x});
        for (int steps = 0; !q.empty(); ++steps) {
            for (int i = q.size(); 0 < i--;) {
                x = q.front();
                q.pop();

                if (x == y) { return steps; }

                if (x % 11 == 0 && visited.insert(x / 11).second) { q.push(x / 11); }
                if (x % 5 == 0 && visited.insert(x / 5).second) { q.push(x / 5); }
                if (visited.insert(x - 1).second) { q.push(x - 1); }
                if (visited.insert(x + 1).second) { q.push(x + 1); }
            }
        }

        assert(false);
        return -1;
    }
};
