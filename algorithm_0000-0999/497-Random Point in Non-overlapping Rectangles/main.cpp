class Solution {
public:
    Solution(vector<vector<int>>& rects)
        : m_rects(rects.size())
        , m_presums(rects.size()) {
        for (int i = 0; i < rects.size(); ++i) {
            int w = rects[i][2] - rects[i][0] + 1, h = rects[i][3] - rects[i][1] + 1;
            m_rects[i] = {rects[i][0], rects[i][1], w, h};
            m_presums[i] = (i > 0 ? m_presums[i - 1] : 0) + w * h;
        }
    }

    vector<int> pick() {
        int pntIdx = std::rand() % m_presums.back();
        int rectIdx = std::distance(m_presums.begin(), std::upper_bound(m_presums.begin(), m_presums.end(), pntIdx));
        int diff = pntIdx - (rectIdx > 0 ? m_presums[rectIdx - 1] : 0);

        const auto& [x, y, w, _] = m_rects[rectIdx];
        return {x + diff % w, y + diff / w};
    }

private:
    vector<tuple<int, int, int, int>> m_rects; // <x, y, w, h>
    vector<int> m_presums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
