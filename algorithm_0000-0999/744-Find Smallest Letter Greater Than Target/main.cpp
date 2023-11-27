class Solution {
public:
    char bsearch(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (letters[mid] > target) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo == letters.size() ? letters.front() : letters[lo];
    }

    char stdlib(vector<char>& letters, char target) {
        auto itr = std::upper_bound(letters.begin(), letters.end(), target);
        if (itr == letters.end()) { itr = letters.begin(); }

        return *itr;
    }

    char nextGreatestLetter(vector<char>& letters, char target) {
        //return bsearch(letters, target);
        return stdlib(letters, target);
    }
};
