class Solution {
public:
    float computeSlope(const vector<int>& p1, const vector<int>& p2) {
        if (p1[0] == p2[0]) {
            return std::numeric_limits<float>::infinity();
        }
        else {
            return float(p2[1] - p1[1]) / float(p2[0] - p1[0]);
        }
    }

    void topDn(vector<vector<int>>& points, vector<bool>& used, int depth, int& ans) {
        if (depth >= ans) {
            return;
        }

        size_t src = std::find(used.begin(), used.end(), false) - used.begin();
        assert(src < used.size());
        size_t cnt = std::count(used.begin() + src, used.end(), false);
        assert(0 < cnt);

        if (cnt <= 2) {
            ans = std::min(ans, depth);
            return;
        }

        used[src] = true;

        unordered_map<float, vector<size_t>> candidates;
        for (size_t i = src + 1; i < points.size(); ++i) {
            if (used[i]) {
                continue;
            }
            float slope = computeSlope(points[src], points[i]);
            candidates[slope].push_back(i);
        }
        assert(1 <= candidates.size());

        if (candidates.size() == 1) {
            ans = std::min(ans, depth);
        }
        else {
            for (auto& [slope, indexes] : candidates) {
                for (size_t index : indexes) {
                    used[index] = true;
                }
                topDn(points, used, depth + 1, ans);
                for (size_t index : indexes) {
                    used[index] = false;
                }
            }
        }

        used[src] = false;
    }

    int minimumLines(vector<vector<int>>& points) {
        vector<bool> used(points.size(), false);
        int ans = INT_MAX;
        topDn(points, used, 1, ans);
        return ans;
    }
};
