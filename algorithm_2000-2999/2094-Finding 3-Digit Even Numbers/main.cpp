class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> cnts(10, 0);
        for (int d : digits) {
            ++cnts[d];
        }

        vector<int> ans;
        for (int i = 100; i <= 999; i += 2) {
            vector<int> tmpCnts = cnts;
            bool flag = true;
            for (int num = i; 0 < num; num /= 10) {
                int d = num % 10;
                if (tmpCnts[d]-- == 0) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
