class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int ballCnt = 0;
        int opCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (boxes[i] == '0') { continue; }
            ballCnt += 1;
            opCnt += i;
        }

        vector<int> ret(n);
        ret[0] = opCnt;
        int cnt = (boxes[0] == '1' ? 1 : 0);
        for (int i = 1; i < n; ++i) {
            opCnt += cnt;
            opCnt -= ballCnt - cnt;
            cnt += (boxes[i] == '1' ? 1 : 0);
            ret[i] = opCnt;
        }

        return ret;
    }
};
