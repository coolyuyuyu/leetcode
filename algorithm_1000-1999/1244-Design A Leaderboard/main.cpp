class Leaderboard {
public:
    Leaderboard() {

    }

    void addScore(int playerId, int score) {
        m_pairs.erase({m_id2score[playerId], playerId});
        m_id2score[playerId] += score;
        m_pairs.insert({m_id2score[playerId], playerId});
    }

    int top(int K) {
        int sum = 0;
        for (auto itr = m_pairs.rbegin(); itr != m_pairs.rend() && K; ++itr, --K) {
            sum += itr->first;
        }

        return sum;
    }

    void reset(int playerId) {
        m_pairs.erase({m_id2score[playerId], playerId});
        m_id2score.erase(playerId);
    }
private:
    set<pair<int, int>> m_pairs;
    unordered_map<int, int> m_id2score;

};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
