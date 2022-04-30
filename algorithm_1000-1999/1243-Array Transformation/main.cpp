class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        for (bool changed = true; changed;) {
            changed = false;
            int pre = arr[0], cur = arr[1], nxt = arr[2];
            for (size_t i = 1; (i + 1) < arr.size(); ++i) {
                if (cur < pre && cur < nxt) {
                    ++arr[i];
                    changed = true;
                }
                else if (pre < cur && nxt < cur) {
                    --arr[i];
                    changed = true;
                }

                if ((i + 2) < arr.size()) {
                    pre = cur;
                    cur = nxt;
                    nxt = arr[i + 2];
                }
            }
        }
        return arr;
    }
};
