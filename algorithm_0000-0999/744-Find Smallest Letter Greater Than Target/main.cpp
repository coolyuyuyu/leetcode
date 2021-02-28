class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        assert(letters.empty() == false);
        if (target >= letters.back() || target < letters.front()) {
            return letters.front();
        }

        ++target;
        size_t lft = 0;
        size_t rht = letters.size();
        while (lft < rht) {
            size_t mid = lft + (rht - lft) / 2;
            if (target <= letters[mid]) {
                rht = mid;
            }
            else {
                lft = mid + 1;
            }
        }

        return rht == letters.size() ? letters.front() : letters[rht];
    }
};