class Solution {
public:
    char nextGreatestLetter_BinarySearch(vector<char>& letters, char target) {
        size_t lo = 0;
        size_t hi = letters.size();
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (letters[mid] <= target) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        assert(lo == hi);

        assert(!letters.empty());;
        return (lo == letters.size() ? letters.front() : letters[lo]);
    }

    char nextGreatestLetter_StdLibrary(vector<char>& letters, char target) {
        auto itr = std::upper_bound(letters.begin(), letters.end(), target);
        if (itr == letters.end()) {
            itr = letters.begin();
        }
        return *itr;
    }

    char nextGreatestLetter(vector<char>& letters, char target) {
        return nextGreatestLetter_BinarySearch(letters, target);
        //return nextGreatestLetter_StdLibrary(letters, target);
    }
};
