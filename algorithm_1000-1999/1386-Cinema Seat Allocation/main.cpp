class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> row2mask;
        for (const auto& seat : reservedSeats) {
            int r = seat[0] - 1, c = seat[1] - 1;
            row2mask[r] |= (1 << c);
        }

        int ret = (n - row2mask.size()) * 2;
        for (const auto& [_, mask] : row2mask) {
            if ((mask & 0b111111110) == 0) { ret += 2; }
            else if ((mask & 0b11110) == 0) { ret += 1; }
            else if ((mask & 0b111100000) == 0) { ret += 1; }
            else if ((mask & 0b1111000) == 0) { ret += 1; }
        }

        return ret;
    }
};
