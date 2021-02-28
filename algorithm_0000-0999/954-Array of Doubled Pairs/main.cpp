class Solution {
public:
    bool canReorderDoubled(vector<int>& numbers) {
        unordered_map<int, int> counts;
        for (int number : numbers) {
            ++counts[number];
        }

        auto comp = [](int lft, int rht){return abs(lft) < abs(rht);};
        sort(numbers.begin(), numbers.end(), comp);

        for (int number : numbers) {
            if (counts[number] == 0) {
                continue;
            }

            if (counts[2 * number] <= 0) {
                return false;
            }

            --counts[number];
            --counts[2 * number];
        }
        return true;
    }
};