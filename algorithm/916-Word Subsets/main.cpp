class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> counts(26, 0); {
            for (const string& b : B) {
                vector<int> tmpCounts(26, 0);
                for (char c : b) {
                    ++tmpCounts[c - 'a'];
                }

                for (int i = 0; i < 26; ++i) {
                    counts[i] = max(counts[i], tmpCounts[i]);
                }
            }
        }
        int totalCount = accumulate(counts.begin(), counts.end(), 0);

        vector<string> ans;
        for (const string& a : A) {
            bool universal = false;
            vector<int> tmpCounts = counts;
            int tmpTotalCount = totalCount;
            for (char c : a) {
                if (tmpCounts[c - 'a'] > 0) {
                    --tmpCounts[c - 'a'];
                    --tmpTotalCount;
                }

                if (tmpTotalCount == 0) {
                    universal = true;
                    break;
                }
            }

            if (universal) {
                ans.push_back(a);
            }
        }

        return ans;
    }
};