class Leaderboard {
public:
    Leaderboard() {
    }

    void addScore(int playerId, int score) {
        auto itr = m_scores.find(m_id2score[playerId]);
        if (itr != m_scores.end()) {
            m_scores.erase(itr);
        }
        m_id2score[playerId] += score;
        m_scores.insert(m_id2score[playerId]);
    }

    int top(int K) {
        int ret = 0;
        for (auto itr = m_scores.rbegin(); itr != m_scores.rend() && K; ++itr, --K) {
            ret += *itr;
        }

        return ret;
    }

    void reset(int playerId) {
        m_scores.erase(m_scores.find(m_id2score[playerId]));
        m_id2score[playerId] = 0;
    }

private:
    unordered_map<int, int> m_id2score;
    multiset<int> m_scores;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
