class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        list<size_t> indexes;
        for (size_t i = 0; i < deck.size(); ++i) {
            indexes.emplace_back(i);
        }

        sort(deck.begin(), deck.end());

        vector<int> ans(deck.size());
        for (size_t i = 0; i < deck.size(); ++i) {
            size_t index = indexes.front();
            indexes.pop_front();
            ans[index] = deck[i];
            if (!indexes.empty()) {
                indexes.push_back(indexes.front());
                indexes.pop_front();
            }
        }
        return ans;
    }
};