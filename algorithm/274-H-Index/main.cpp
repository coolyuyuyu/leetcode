class Solution {
public:
    int hIndex_BruteForce(const vector<int>& citations) {
        int n = citations.size();

        for (int i = n; 0 < n; --i) {
            int count = std::count_if(citations.begin(), citations.end(), [&](int c){ return (i <= c); });
            if (count >= i) {
                return i;
            }
        }

        return 0;
    }

    int hIndex_Sort_LinearSearch(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int n = citations.size();
        for (int i = 0; i < n; ++i) {
            if (citations[i] >= (n - i)) {
                return n - i;
            }
        }

        return 0;
    }

    int hIndex_Sort_BinarySearch(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int n = citations.size();
        int lft = 0, rht = citations.size();
        while (lft < rht) {
            int mid = lft + (rht - lft) / 2;
            if (citations[mid] >= n - mid) {
                rht = mid;
            }
            else {
                lft = mid + 1;
            }
        }

        return n - rht;
    }

    int hIndex(vector<int>& citations) {
        //return hIndex_BruteForce(citations);
        //return hIndex_Sort_LinearSearch(citations);
        return hIndex_Sort_BinarySearch(citations);
    }
};