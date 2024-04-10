class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        for (int i = 0; i < deck.size(); ++i) {
            q.push(i);
        }

        std::sort(deck.begin(), deck.end());

        vector<int> ret(deck.size());
        for (int i = 0; !q.empty();) {
            ret[q.front()] = deck[i++];
            q.pop();
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return ret;
    }
};
