class Solution {
public:
    int shortestDistance1(const vector<string>& words, const string& word1, const string& word2) {
        size_t index1 = 0, index2 = 0;
        bool found1 = false, found2 = false;
        size_t minDistance = numeric_limits<size_t>::max();
        for (size_t i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                found1 = true;
                index1 = i;
                if (found2) {
                    minDistance = min(minDistance, index1 - index2);
                }
            }
            else if (words[i] == word2) {
                found2 = true;
                index2 = i;
                if (found1) {
                    minDistance = min(minDistance, index2 - index1);
                }
            }
        }

        return minDistance;
    }

    size_t searchInsert(const vector<size_t> nums, size_t target) {
        size_t lo = 0, hi = nums.size();
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        return lo;
    }

    size_t minDiff(const vector<size_t>& nums, size_t target) {
        assert(!nums.empty());

        size_t index = searchInsert(nums, target);
        if (nums.size() <= index) {
            return target - nums.back();
        }
        else {
            size_t diff = nums[index] - target;
            if (1 <= index) {
                diff = min(diff, target - nums[index - 1]);
            }
            return diff;
        }
    }

    int shortestDistance2(const vector<string>& words, const string& word1, const string& word2) {
        vector<size_t> indexes1, indexes2;
        for (size_t i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                indexes1.push_back(i);
            }
            else if (words[i] == word2) {
                indexes2.push_back(i);
            }
        }

        size_t minDistance = numeric_limits<size_t>::max();
        if (indexes1.size() <= indexes2.size()) {
            for (size_t index1 : indexes1) {
                minDistance = min(minDistance, minDiff(indexes2, index1));
            }
        }
        else {
            for (size_t index2 : indexes2) {
                minDistance = min(minDistance, minDiff(indexes1, index2));
            }
        }

        return minDistance;
    }

    int shortestDistance(vector<string>& words, string word1, string word2) {
        //return shortestDistance1(words, word1, word2);

        return shortestDistance2(words, word1, word2);
    }
};