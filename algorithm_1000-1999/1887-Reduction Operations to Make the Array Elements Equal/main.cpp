class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> cnts;
        for (int num : nums) {
            ++cnts[num];
        }

        auto itr = cnts.begin();
        ++itr;

        int ret = 0;
        for (int i = 1; itr != cnts.end(); ++i, ++itr) {
            ret += (itr->second) * i;
        }

        return ret;
    }
};
