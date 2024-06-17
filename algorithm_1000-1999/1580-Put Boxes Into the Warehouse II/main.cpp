class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.rbegin(), boxes.rend());

        int lft = 0, rht = warehouse.size() - 1, ret = 0;
        for (int box : boxes) {
            if (lft > rht) { break; }
            if (box > std::max(warehouse[lft], warehouse[rht])) { continue; }

            if (box <= warehouse[lft] && box <= warehouse[rht]) {
                warehouse[lft] < warehouse[rht] ? ++lft : --rht;
            }
            else if (box <= warehouse[lft]) {
                ++lft;
            }
            else {
                --rht;
            }
            ++ret;
        }

        return ret;
    }
};
