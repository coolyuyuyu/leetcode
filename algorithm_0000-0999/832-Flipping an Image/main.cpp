class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (vector<int>& row : image) {
            std::reverse(row.begin(), row.end());
            std::for_each(row.begin(), row.end(), [&](int& b) { b = (b == 1 ? 0 : 1); });
        }
        return image;
    }
};
