class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ret = -1;
        for (int i = 0; i < capacity.size(); ++i) {
            if (capacity[i] >= itemSize && (ret == -1 || capacity[i] < capacity[ret])) {
                ret = i;
            }
        }

        return ret;
    }
};
