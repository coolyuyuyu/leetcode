/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
class Solution {
public:
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        unordered_set<int> categories;
        for (int i = 0; i < n; ++i) {
            bool found = false;
            for (int j : categories) {
                if (categoryHandler->haveSameCategory(i, j)) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                categories.insert(i);
            }
        }

        return categories.size();
    }
};
