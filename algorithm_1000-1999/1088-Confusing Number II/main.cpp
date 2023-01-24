class Solution {
public:
    bool checkConfusing(int num) {
        int reversed = 0;
        for (int tmp = num; tmp; tmp /= 10) {
            reversed *= 10;

            int d = tmp % 10;
            switch(d) {
                case 2:
                case 3:
                case 4:
                case 5:
                case 7:
                    return false;
                case 0:
                case 1:
                case 8:
                    reversed += d;
                    break;
                case 6:
                    reversed += 9;
                    break;
                case 9:
                    reversed += 6;
                    break;
            }
        }

        return reversed != num;
    }

    int confusingNumberII(int n) {
        int ret = 0;
        queue<long> q({1, 6, 8, 9});
        while (!q.empty()) {
            long num = q.front();
            q.pop();

            if (n < num) {
                continue;
            }

            if (checkConfusing(num)) {
                ++ret;
            }

            num *= 10;
            q.push(num + 0);
            q.push(num + 1);
            q.push(num + 6);
            q.push(num + 8);
            q.push(num + 9);
        }
        return ret;
    }
};
