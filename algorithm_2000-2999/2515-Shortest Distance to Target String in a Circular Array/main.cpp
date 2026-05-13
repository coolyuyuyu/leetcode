class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        for (int step = 0, n = words.size(); step < n; ++step) {
            if (words[(startIndex + step) % n] == target) { return step; }
            if (words[(startIndex + n - step) % n] == target) { return step; }
        }

        return -1;
    }
};
