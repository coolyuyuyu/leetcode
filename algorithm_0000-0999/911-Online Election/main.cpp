class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times)
        : m_leaders(persons.size()) {
        unordered_map<int, int> votes;
        int leader = -1, vote = 0;
        for (int i = 0; i < persons.size(); ++i) {
            if (++votes[persons[i]] >= votes[leader]) {
                leader = persons[i];
            }
            m_leaders[i] = {times[i], leader};
        }
    }

    int q(int t) {
        auto itr = std::prev(std::upper_bound(m_leaders.begin(), m_leaders.end(), make_pair(t, INT_MAX)));
        return itr->second;
    }

private:
    vector<pair<int, int>> m_leaders;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
