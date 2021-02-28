class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char c : tasks) {
            ++counts[c];
        }

        int maxCount = 0;
        int maxCountOccurence = 0;
        for (const auto& p : counts) {
            if (maxCount < p.second) {
                maxCount = p.second;
                maxCountOccurence = 1;
            }
            else if (maxCount == p.second) {
                ++maxCountOccurence;
            }
        }

        int ans = (maxCount - 1) * (n + 1) + maxCountOccurence;
        return max(int(tasks.size()), ans);
    }
};