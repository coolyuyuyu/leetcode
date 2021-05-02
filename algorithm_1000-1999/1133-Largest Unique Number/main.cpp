class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        map<int, int> counts;
        for (int num : A) {
            ++counts[num];
        }

        for (auto itr = counts.rbegin(); itr != counts.rend(); ++itr) {
            if (itr->second == 1) {
                return itr->first;
            }
        }

        return -1;
    }
};
