class Solution {
public:
    string losingPlayer(int x, int y) {
        int round = std::min(x / 1, y / 4);
        return round & 1 ? "Alice" : "Bob";
    }
};
