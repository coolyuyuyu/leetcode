class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> candidatesX = {1};
        if (1 < x) {
            int newX;
            while ((newX = candidatesX.back() * x) < bound) {
                candidatesX.push_back(newX);
            }
        }

        vector<int> candidatesY = {1};
        if (1 < y) {
            int newY;
            while ((newY = candidatesY.back() * y) < bound) {
                candidatesY.push_back(newY);
            }
        }

        set<int> ansSet;
        for (int newX : candidatesX) {
            for (int newY : candidatesY) {
                int ans = newX + newY;
                if (bound < ans) {
                    break;
                }

                ansSet.insert(ans);
            }
        }

        return vector<int>(ansSet.begin(), ansSet.end());
    }
};