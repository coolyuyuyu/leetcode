class Solution {
public:
    vector<int> constructRectangle(int area) {
        if (area == 0) {
            return {};
        }
        
        int width = sqrt(area);
        while (area % width) {
            --width;
        }

        return {area / width, width};
    }
};