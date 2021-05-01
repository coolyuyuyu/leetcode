class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int amount = 0;
        for (const auto& s : shift) {
            if (s[0] == 1) {
                amount += s[1];
            }
            else {
                amount -= s[1];
            }
        }
        if (0 <= amount) {
            amount %= s.size();
        }
        else {
            amount = -(-amount % s.size());
        }

        rotate(s.begin(), s.begin()+ (0 < amount ? s.size() - amount : -amount), s.end());
        return s;
    }
};
