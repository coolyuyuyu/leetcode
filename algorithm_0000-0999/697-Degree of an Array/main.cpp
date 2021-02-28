class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, pair<size_t, int>> indexDegreePairs;
        int maxDegree = INT_MIN;
        int minLen = INT_MAX;
        for (size_t i = 0; i < nums.size(); ++i) {
            int degree, len; {
                auto p = indexDegreePairs.insert({ nums[i], { i, 1 } });
                if (!p.second) {
                    pair<size_t, int>& indexDegreePair = p.first->second;
                    ++indexDegreePair.second;

                    degree = indexDegreePair.second;
                    len = i - indexDegreePair.first + 1;
                }
                else {
                    degree = 1;
                    len = 1;
                }
            }

            if (maxDegree < degree) {
                maxDegree = degree;
                minLen = len;
            }
            else if (maxDegree == degree) {
                if (len < minLen) {
                    minLen = len;
                }
            }
        }

        return minLen;
    }
};
