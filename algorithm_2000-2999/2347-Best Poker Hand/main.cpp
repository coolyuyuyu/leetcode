class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (std::all_of(suits.begin() + 1, suits.end(), [&](int suit) { return suit == suits[0];})) {
            return "Flush";
        }

        vector<int> cnts(13, 0);
        for (int rank : ranks) {
            ++cnts[rank - 1];
        }
        if (std::any_of(cnts.begin(), cnts.end(), [](int cnt){ return 3 <= cnt; })) {
            return "Three of a Kind";
        }
        if (std::any_of(cnts.begin(), cnts.end(), [](int cnt){ return 2 <= cnt; })) {
            return "Pair";
        }

        return "High Card";
    }
};
