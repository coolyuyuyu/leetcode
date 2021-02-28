class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        vector<int> pos(row.size());
        for (size_t i = 0; i < row.size(); ++i) {
            pos[row[i]] = i;
        }

        int ans = 0;
        for (size_t i = 0; i < row.size(); ++i) {
            if (i % 2 == 0) {
                continue;
            }

            int preNum = row[i - 1];
            int num1 = row[i];
            int num2 = preNum + (preNum % 2 == 1 ? -1 : 1);
            if (num1 == num2) {
                continue;
            }

            swap(row[i], row[pos[num2]]);
            swap(pos[num1], pos[num2]);

            ++ans;
        }

        return ans;
    }
};