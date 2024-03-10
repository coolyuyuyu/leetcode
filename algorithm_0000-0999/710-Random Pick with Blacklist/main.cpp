class Strategy {
public:
    virtual int pick() = 0;
};

class BSearchKthWhite : public Strategy {
public:
    BSearchKthWhite(int n, vector<int>& blacklist)
        : m_n(n)
        , m_blacks(blacklist) {
        sort(m_blacks.begin(), m_blacks.end());
    }

    int pick() {
        int k = rand() % (m_n - m_blacks.size()) ;

        int lo = 0, hi = m_n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid - std::distance(m_blacks.begin(), std::upper_bound(m_blacks.begin(), m_blacks.end(), mid)) >= k) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }

private:
    int m_n;
    vector<int>& m_blacks;
};

class MapBlack2White : public Strategy {
public:
    MapBlack2White(int n, vector<int>& blacklist)
        : m_n(n)
        , m_m(blacklist.size()) {
        unordered_set<int> blacks(blacklist.begin(), blacklist.end());
        int white = m_n - 1;
        for (int black : blacklist) {
            if (black >= m_n - m_m) { continue; }
            while (blacks.find(white) != blacks.end()) {
                --white;
            }
            m_black2white[black] = white--;
        }
    }

    int pick() {
        int k = rand() % (m_n - m_m);
        if (m_black2white.find(k) == m_black2white.end()) {
            return k;
        }
        else {
            return m_black2white[k];
        }
    }

private:
    int m_n;
    int m_m;
    unordered_map<int, int> m_black2white;
};


class Solution {
public:
    Solution(int n, vector<int>& blacklist)
        //: m_strategy(new BSearchKthWhite(n, blacklist)) {
        : m_strategy(new MapBlack2White(n, blacklist)) {

    }

    int pick() {
        return m_strategy->pick();
    }

private:
    Strategy* m_strategy;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
