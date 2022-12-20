class Solution {
public:
    int dist(const vector<vector<int>>& workers, size_t i, const vector<vector<int>>& bikes, size_t j) {
        return abs(bikes[j][0] - workers[i][0]) + abs(bikes[j][1] - workers[i][1]);
    }

    void dfs1(const vector<vector<int>>& workers, const vector<vector<int>>& bikes, size_t i, vector<bool>& used, int sumDist, int& ans) {
        if (workers.size() <= i) {
            ans = std::min(ans, sumDist);
            return;
        }
        if (ans <= sumDist) {
            return;
        }

        for (size_t j = 0; j < bikes.size(); ++j) {
            if (used[j]) {
                continue;
            }

            used[j] = true;
            dfs1(workers, bikes, i + 1, used, sumDist + dist(workers, i, bikes, j), ans);
            used[j] = false;
        }
    }

    int dfs1(const vector<vector<int>>& workers, const vector<vector<int>>& bikes) {
        vector<bool> used(bikes.size(), false);
        int ans = INT_MAX;
        dfs1(workers, bikes, 0, used, 0, ans);
        return ans;
    }

    int dfs2(const vector<vector<int>>& workers, const vector<vector<int>>& bikes, size_t i, size_t state, vector<int>& cache) {
        if (workers.size() <= i) {
            return 0;
        }
        if (cache[state] != 0) {
            return cache[state];
        }

        int minDist = INT_MAX;
        for (size_t j = 0; j < bikes.size(); ++j) {
            if ((state & (1 << j)) == 0) {
                minDist = std::min(minDist, dist(workers, i, bikes, j) + dfs2(workers, bikes, i + 1, state | (1 << j), cache));
            }
        }

        return cache[state] = minDist;
    }

    int dfs2(const vector<vector<int>>& workers, const vector<vector<int>>& bikes) {
        vector<int> cache(1 << bikes.size(), 0);
        return dfs2(workers, bikes, 0, 0, cache);
    }

    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        //return dfs1(workers, bikes);
        return dfs2(workers, bikes);
    }
};
