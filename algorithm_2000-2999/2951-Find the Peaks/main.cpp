class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> ret;
        for (int i = 1; i + 1 < mountain.size();) {
            if (mountain[i - 1] < mountain[i] && mountain[i] > mountain[i + 1]) {
                ret.push_back(i);
                i += 2;
            }
            else {
                i += 1;
            }
        }

        return ret;
    }
};
