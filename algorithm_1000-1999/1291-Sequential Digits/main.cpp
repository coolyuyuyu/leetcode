class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for (int d = 1; d <= 9; ++d) {
            q.push(d);
        }

        vector<int> ret;
        while (!q.empty()) {
            int num = q.front();
            q.pop();

            if (num > high) {
                continue;
            }

            if (low <= num && num <= high) {
                ret.push_back(num);
            }

            if ((num % 10) < 9) {
                q.push(num * 10 + num % 10 + 1);
            }
        }

        return ret;
    }
};
