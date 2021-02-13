#include <algorithm>

class Solution {
public:
    int hIndex_BruteForce(const vector<int>& citations) {
        int h = 0;

        for (int tmpH = 1; tmpH <= citations.size(); ++tmpH) {
            int c = count_if(citations.begin(), citations.end(), [&](int citation) { return (tmpH <= citation); });
            if (tmpH <= c) {
                h = tmpH;
            }
            else {
                break;
            }
        }
        return h;
    }

    int hIndex_Sort(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int n = citations.size();
        for (int i = 0; i < n; ++i) {
            if (citations[i] >= (n - i)) {
                return n - i;
            }
        }

        return 0;
    }

    int hIndex(vector<int>& citations) {
        return hIndex_Sort(citations);
    }
};