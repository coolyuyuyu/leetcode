class Solution {
public:
    vector<int> constructRectangle(int area) {
        assert(1 <= area);

        int width = sqrt(area);
        while (area % width != 0) {
            --width;
        }

        return {area / width, width};
    }
};