class Strategy {
public:
    virtual int pick() = 0;
};

class MapBlack : public Strategy {
public:
    MapBlack(int n, vector<int>& blacklist)
        : m_n(n)
        , m_m(blacklist.size()){

        unordered_set<int> blackNums(blacklist.begin(), blacklist.end());
        int num = m_n - 1;
        for (int blackNum : blackNums) {
            if (blackNum >= m_n - m_m) { continue; }
            while (blackNums.find(num) != blackNums.end()) {
                num--;
            }
            m_mappedNums[blackNum] = num--;
        }
    }

    int pick() {
        int idx = rand() % (m_n - m_m);
        if (m_mappedNums.find(idx) != m_mappedNums.end()) {
            return m_mappedNums[idx];
        }
        else {
            return idx;
        }
    }

private:
    int m_n;
    int m_m;
    unordered_map<int, int> m_mappedNums;
};


class Solution {
public:
    Solution(int n, vector<int>& blacklist)
        : m_strategy(new MapBlack(n, blacklist)) {
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
