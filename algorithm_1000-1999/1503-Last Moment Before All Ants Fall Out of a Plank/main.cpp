class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ret = 0;
        for (int pos : left) {
            ret = std::max(ret, pos);
        }
        for (int pos : right) {
            ret = std::max(ret, n - pos);
        }    

        return ret;
    }
};
